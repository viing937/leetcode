impl Solution {
    #[allow(dead_code)]
    pub fn paint_walls(cost: Vec<i32>, time: Vec<i32>) -> i32 {
        let n = cost.len();
        let mut dp = vec![i32::MAX >> 2; n + 1];
        dp[0] = 0;
        for i in 0..n {
            for j in (0..=n).rev() {
                let cur_time = time[i] as usize;
                if j > cur_time {
                    dp[j] = dp[j].min(dp[j - cur_time - 1] + cost[i]);
                } else {
                    dp[j] = dp[j].min(dp[0] + cost[i]);
                }
            }
        }
        dp[n]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
