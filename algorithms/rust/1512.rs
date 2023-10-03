use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for num in nums {
            *cnt.entry(num).or_insert(0) += 1;
        }

        let mut rslt = 0;
        for (_, cnt) in cnt.into_iter() {
            rslt += cnt * (cnt - 1) / 2;
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
