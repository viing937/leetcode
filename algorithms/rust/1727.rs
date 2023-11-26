impl Solution {
    #[allow(dead_code)]
    pub fn largest_submatrix(mut matrix: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (matrix.len(), matrix[0].len());

        for i in 1..m {
            for j in 0..n {
                if matrix[i][j] != 0 {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        let mut rslt = 0;
        for row in matrix.iter_mut() {
            row.sort_by(|a, b| b.cmp(a));
            for (j, cnt) in row.iter().enumerate() {
                rslt = rslt.max(cnt * (j as i32 + 1));
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
