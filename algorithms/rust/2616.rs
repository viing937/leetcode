impl Solution {
    #[allow(dead_code)]
    pub fn minimize_max(mut nums: Vec<i32>, p: i32) -> i32 {
        let n = nums.len();
        nums.sort();
        let (mut left, mut right) = (0, nums[n - 1] - nums[0]);
        while left < right {
            let mid = left + (right - left) / 2;
            if Self::get_threshold_pairs(&nums, mid) >= p {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        left
    }

    fn get_threshold_pairs(nums: &Vec<i32>, x: i32) -> i32 {
        let n = nums.len();
        let mut cnt = 0;
        let mut idx = 0;
        while idx + 1 < n {
            if nums[idx + 1] - nums[idx] <= x {
                cnt += 1;
                idx += 2;
            } else {
                idx += 1;
            }
        }
        cnt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
