use std::mem;

impl Solution {
    #[allow(dead_code)]
    pub fn num_ways(steps: i32, arr_len: i32) -> i32 {
        let mod_ = 1_000_000_000 + 7;
        let steps = steps as usize;
        let arr_len = (steps + 1).min(arr_len as usize);
        let mut dp = vec![0; arr_len];
        dp[0] = 1;
        for _ in 0..steps {
            let mut dp_new = vec![0; arr_len];
            for i in 0..arr_len {
                dp_new[i] = dp[i];
                if i > 0 {
                    dp_new[i] = (dp_new[i] + dp[i - 1]) % mod_;
                }
                if i + 1 < arr_len {
                    dp_new[i] = (dp_new[i] + dp[i + 1]) % mod_;
                }
            }
            mem::swap(&mut dp, &mut dp_new);
        }
        dp[0]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
