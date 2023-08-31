impl Solution {
    #[allow(dead_code)]
    pub fn min_taps(n: i32, ranges: Vec<i32>) -> i32 {
        let n = n as usize;
        let inf = n * n;

        let mut dp = vec![inf; n + 1];
        dp[0] = 0;

        (0..=n).for_each(|i| {
            let left = 0.max(i as i32 - ranges[i]) as usize;
            let right = n.min(i + ranges[i] as usize);

            for j in left..=right {
                dp[right] = dp[right].min(dp[j] + 1);
            }
        });

        if dp[n] != inf {
            dp[n] as i32
        } else {
            -1
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
