impl Solution {
    #[allow(dead_code)]
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (obstacle_grid.len(), obstacle_grid[0].len());
        if obstacle_grid[0][0] == 1 {
            return 0;
        }
        let mut dp = vec![vec![0; n]; m];
        dp[0][0] = 1;
        for i in 0..m {
            for j in 0..n {
                if obstacle_grid[i][j] == 1 {
                    continue;
                }
                if i >= 1 {
                    dp[i][j] += dp[i - 1][j];
                }
                if j >= 1 {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        dp[m - 1][n - 1]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
