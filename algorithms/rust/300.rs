impl Solution {
    #[allow(dead_code)]
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut dp = vec![1; nums.len()];
        for (i, x) in nums.iter().enumerate() {
            for (j, y) in nums.iter().enumerate().take(i) {
                if x > y {
                    dp[i] = dp[i].max(dp[j] + 1);
                }
            }
        }
        *dp.iter().max().unwrap()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
