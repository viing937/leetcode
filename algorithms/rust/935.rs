use std::mem;

impl Solution {
    #[allow(dead_code)]
    pub fn knight_dialer(n: i32) -> i32 {
        let jump_map = vec![
            vec![4, 6],
            vec![8, 6],
            vec![7, 9],
            vec![4, 8],
            vec![0, 3, 9],
            vec![],
            vec![0, 1, 7],
            vec![2, 6],
            vec![1, 3],
            vec![4, 2],
        ];
        let mod_ = 1_000_000_000 + 7;
        let mut dp = vec![1; 10];
        for _ in 2..=n {
            let mut new_dp = vec![0; 10];
            for dst in 0..10 {
                for &src in jump_map[dst].iter() {
                    new_dp[dst] = (new_dp[dst] + dp[src]) % mod_;
                }
            }
            mem::swap(&mut dp, &mut new_dp);
        }
        let mut rslt = 0;
        for t in dp {
            rslt = (rslt + t) % mod_;
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
