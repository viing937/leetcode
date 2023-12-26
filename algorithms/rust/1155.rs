use std::mem;

impl Solution {
    #[allow(dead_code)]
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
        let mod_ = 1_000_000_000 + 7;
        let (n, k, target) = (n as usize, k as usize, target as usize);
        let mut dp = vec![0; target + 1];

        dp[0] = 1;
        for _ in 0..n {
            let mut new_dp = vec![0; target + 1];
            for i in 0..target {
                for j in 1..=k {
                    if i + j > target {
                        break;
                    }
                    new_dp[i + j] = (new_dp[i + j] + dp[i]) % mod_;
                }
            }
            mem::swap(&mut dp, &mut new_dp);
        }
        dp[target]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
