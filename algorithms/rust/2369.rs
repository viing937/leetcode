impl Solution {
    #[allow(dead_code)]
    pub fn valid_partition(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut dp = vec![false; n + 1];
        dp[0] = true;
        for i in 0..n {
            if i >= 1 && nums[i] == nums[i - 1] && dp[i - 1] {
                dp[i + 1] = true;
            }
            if i >= 2 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && dp[i - 2] {
                dp[i + 1] = true;
            }
            if i >= 2 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2 && dp[i - 2] {
                dp[i + 1] = true;
            }
        }
        dp[n]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
