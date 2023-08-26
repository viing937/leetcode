impl Solution {
    #[allow(dead_code)]
    pub fn find_longest_chain(mut pairs: Vec<Vec<i32>>) -> i32 {
        pairs.sort();
        let mut dp = vec![1; pairs.len()];

        let mut rslt = 1;
        for i in 0..pairs.len() {
            for j in i..pairs.len() {
                if pairs[j][0] > pairs[i][1] {
                    dp[j] = dp[j].max(dp[i] + 1);
                    rslt = rslt.max(dp[j]);
                }
            }
        }

        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
