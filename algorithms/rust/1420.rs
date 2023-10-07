impl Solution {
    const MOD: usize = 1_000_000_000 + 7;

    #[allow(dead_code)]
    pub fn num_of_arrays(n: i32, m: i32, k: i32) -> i32 {
        let (n, m, k) = (n as usize, m as usize, k as usize);
        let mut dp = vec![vec![0; m]; k];
        for i in 0..m {
            dp[0][i] = 1;
        }
        for _ in 0..n - 1 {
            for i in (0..k).rev() {
                let mut cur = 0;
                for j in 0..m {
                    dp[i][j] = (dp[i][j] * (j + 1) + cur) % Self::MOD;
                    if i > 0 {
                        cur = (cur + dp[i - 1][j]) % Self::MOD;
                    }
                }
            }
        }
        let mut result = 0;
        for val in dp[k - 1].iter() {
            result = (result + val) % Self::MOD;
        }
        result as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
