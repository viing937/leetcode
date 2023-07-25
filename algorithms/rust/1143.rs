impl Solution {
    #[allow(unused)]
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let (m, n) = (text1.len(), text2.len());
        let mut dp = vec![vec![0; n + 1]; m + 1];
        for (i, ch1) in text1.chars().enumerate() {
            for (j, ch2) in text2.chars().enumerate() {
                dp[i + 1][j + 1] = (dp[i][j] + if ch1 == ch2 { 1 } else { 0 })
                    .max(dp[i + 1][j])
                    .max(dp[i][j + 1]);
            }
        }
        dp[m][n]
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
