impl Solution {
    #[allow(dead_code)]
    pub fn maximum_score(nums: Vec<i32>, k: i32) -> i32 {
        let (mut left, mut right) = (k as usize, k as usize);
        let mut min_val = nums[left];
        let mut max_score = nums[left];
        while left > 0 || right < nums.len() - 1 {
            if left == 0 || (right + 1 < nums.len() && nums[right + 1] > nums[left - 1]) {
                right += 1;
            } else {
                left -= 1;
            }
            min_val = min_val.min(nums[left]).min(nums[right]);
            max_score = max_score.max(min_val * (right - left + 1) as i32);
        }
        max_score
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
