impl Solution {
    #[allow(dead_code)]
    pub fn sort_array_by_parity(mut nums: Vec<i32>) -> Vec<i32> {
        let mut left = 0;
        for i in 0..nums.len() {
            if nums[i] % 2 == 0 {
                nums.swap(i, left);
                left += 1;
            }
        }
        nums
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
