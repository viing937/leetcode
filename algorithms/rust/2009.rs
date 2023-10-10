impl Solution {
    #[allow(dead_code)]
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        nums.sort();
        nums.dedup();

        let mut result = i32::MAX;
        for (i, &s) in nums.iter().enumerate() {
            let e = s + n - 1;
            let j = nums.partition_point(|&x| x <= e) as i32;
            result = result.min(n - j + i as i32);
        }
        result
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
