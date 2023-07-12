use std::collections::HashMap;

impl Solution {
    #[allow(unused)]
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen = HashMap::new();
        for (i, &num) in nums.iter().enumerate() {
            let complement = target - num;
            if seen.contains_key(&complement) {
                return vec![seen[&complement], i as i32];
            }
            seen.insert(num, i as i32);
        }
        return vec![];
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
