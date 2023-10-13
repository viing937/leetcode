impl Solution {
    #[allow(dead_code)]
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut dp = vec![0; cost.len() + 1];
        for i in 2..=cost.len() {
            dp[i] = (dp[i - 2] + cost[i - 2]).min(dp[i - 1] + cost[i - 1]);
        }
        *dp.last().unwrap()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
