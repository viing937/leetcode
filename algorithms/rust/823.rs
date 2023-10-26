use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn num_factored_binary_trees(mut arr: Vec<i32>) -> i32 {
        let mod_ = 1_000_000_007;
        arr.sort();

        let num_idx: HashMap<i32, usize> = arr
            .iter()
            .enumerate()
            .map(|(idx, &num)| (num, idx))
            .collect();

        let mut dp = vec![1; arr.len()];
        let mut rslt: usize = 0;
        for i in 0..dp.len() {
            for j in 0..i {
                if arr[i] % arr[j] == 0 {
                    if let Some(&k) = num_idx.get(&(arr[i] / arr[j])) {
                        dp[i] = (dp[i] + dp[j] * dp[k]) % mod_;
                    }
                }
            }
            rslt = (rslt + dp[i]) % mod_;
        }
        rslt as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
