impl Solution {
    #[allow(dead_code)]
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let amount = amount as usize;
        let mut dp = vec![0; amount + 1];
        dp[0] = 1;
        for coin in coins.into_iter().map(|x| x as usize) {
            for i in coin..=amount {
                dp[i] += dp[i - coin];
            }
        }
        dp[amount]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
