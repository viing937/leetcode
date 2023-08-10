impl Solution {
    #[allow(dead_code)]
    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        if nums[0] == target {
            return true;
        }
        let (mut left, mut right) = (0, nums.len() as i32 - 1);
        while right >= left && nums[left as usize] == nums[right as usize] {
            right -= 1;
        }
        while left <= right {
            let mid = left + (right - left) / 2;
            let mid_value = nums[mid as usize];
            if mid_value == target {
                return true;
            }
            if mid_value >= nums[0] && (target > mid_value || target < nums[0])
                || target < nums[0] && target > mid_value
            {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        false
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
