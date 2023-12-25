impl Solution {
    #[allow(dead_code)]
    pub fn num_decodings(s: String) -> i32 {
        let n = s.len();
        let mut dp = vec![0; n + 1];
        dp[0] = 1;

        let s: Vec<char> = s.chars().collect();
        for i in 0..n {
            if s[i] >= '1' && s[i] <= '9' {
                dp[i + 1] += dp[i];
            }
            if i > 0 && s[i - 1] == '1' && s[i] >= '0' && s[i] <= '9' {
                dp[i + 1] += dp[i - 1];
            }
            if i > 0 && s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6' {
                dp[i + 1] += dp[i - 1];
            }
        }

        dp[n]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
