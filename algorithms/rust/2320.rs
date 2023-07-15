impl Solution {
    #[allow(unused)]
    pub fn count_house_placements(n: i32) -> i32 {
        if n == 1 {
            return 2 * 2;
        }
        let mod_ = 1_000_000_000 + 7;
        let n = n as usize;
        let mut dp = vec![vec![0 as i64; n]; 2];
        dp[0][0] = 1;
        dp[1][0] = 1;
        for i in 1..n {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod_;
            dp[1][i] = dp[0][i - 1];
        }
        let one_side = (dp[0][n - 1] + dp[1][n - 1]) % mod_;
        return (one_side.pow(2) % mod_) as i32;
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
