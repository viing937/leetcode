impl Solution {
    #[allow(dead_code)]
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let target = target as usize;
        let mut dp = vec![0; target + 1];
        dp[0] = 1;

        for i in 1..=target {
            for &num in nums.iter() {
                let num = num as usize;
                if i >= num {
                    dp[i] += dp[i - num];
                }
            }
        }

        dp[target]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
