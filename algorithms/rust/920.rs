impl Solution {
    #[allow(unused)]
    pub fn num_music_playlists(n: i32, goal: i32, k: i32) -> i32 {
        let mod_ = 1_000_000_000 + 7;
        let (n, goal, k) = (n as usize, goal as usize, k as usize);
        let mut dp = vec![vec![0; goal + 1]; n + 1];
        dp[0][0] = 1;
        for i in 1..=n {
            for j in i..=goal {
                dp[i][j] = (dp[i - 1][j - 1] * (n - i + 1)) % mod_;
                if i > k {
                    dp[i][j] = (dp[i][j] + (dp[i][j - 1] * (i - k) % mod_)) % mod_;
                }
            }
        }
        dp[n][goal] as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
