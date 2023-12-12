use std::mem;

impl Solution {
    #[allow(dead_code)]
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let (mut i, mut j) = (0, 1);
        if nums[i] < nums[j] {
            mem::swap(&mut i, &mut j);
        }
        for (idx, &num) in nums.iter().enumerate().skip(2) {
            if num > nums[i] {
                j = i;
                i = idx;
            } else if num > nums[j] {
                j = idx;
            }
        }
        (nums[i] - 1) * (nums[j] - 1)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
