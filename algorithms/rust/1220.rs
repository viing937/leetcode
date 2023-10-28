use std::mem;

impl Solution {
    #[allow(dead_code)]
    pub fn count_vowel_permutation(n: i32) -> i32 {
        if n == 1 {
            return 5;
        }

        let mod_ = 1_000_000_007;

        let mut dp: Vec<usize> = vec![1; 5];
        for _ in 2..=n {
            let mut new_dp = vec![0; 5];

            // Each vowel 'a' may only be followed by an 'e'
            new_dp[1] = (new_dp[1] + dp[0]) % mod_;

            // Each vowel 'e' may only be followed by an 'a' or an 'i'
            new_dp[0] = (new_dp[0] + dp[1]) % mod_;
            new_dp[2] = (new_dp[2] + dp[1]) % mod_;

            // Each vowel 'i' may not be followed by another 'i'
            new_dp[0] = (new_dp[0] + dp[2]) % mod_;
            new_dp[1] = (new_dp[1] + dp[2]) % mod_;
            new_dp[3] = (new_dp[3] + dp[2]) % mod_;
            new_dp[4] = (new_dp[4] + dp[2]) % mod_;

            // Each vowel 'o' may only be followed by an 'i' or a 'u'
            new_dp[2] = (new_dp[2] + dp[3]) % mod_;
            new_dp[4] = (new_dp[4] + dp[3]) % mod_;

            // Each vowel 'u' may only be followed by an 'a'
            new_dp[0] = (new_dp[0] + dp[4]) % mod_;

            mem::swap(&mut dp, &mut new_dp);
        }

        let mut rslt = 0;
        for c in dp {
            rslt = (rslt + c) % mod_;
        }
        rslt as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
