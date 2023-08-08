impl Solution {
    #[allow(dead_code)]
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut left, mut right) = (0_i32, nums.len() as i32 - 1);
        while left <= right {
            let mid = left + (right - left) / 2;
            let mid_val = nums[mid as usize];
            if mid_val == target {
                return mid;
            }

            if (target > mid_val || target < nums[0]) && mid_val >= nums[0]
                || target < nums[0] && target > mid_val
            {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        -1
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
