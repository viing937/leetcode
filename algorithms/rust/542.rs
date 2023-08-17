impl Solution {
    #[allow(dead_code)]
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (mat.len(), mat[0].len());
        let mut dp = vec![vec![(m * n) as i32; n]; m];
        for i in 0..m {
            for j in 0..n {
                if mat[i][j] == 0 {
                    dp[i][j] = 0;
                }
                if i >= 1 {
                    dp[i][j] = dp[i][j].min(dp[i - 1][j] + 1);
                }
                if j >= 1 {
                    dp[i][j] = dp[i][j].min(dp[i][j - 1] + 1);
                }
            }
        }
        for i in (0..m).rev() {
            for j in (0..n).rev() {
                if i + 1 < m {
                    dp[i][j] = dp[i][j].min(dp[i + 1][j] + 1);
                }
                if j + 1 < n {
                    dp[i][j] = dp[i][j].min(dp[i][j + 1] + 1);
                }
            }
        }
        dp
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
