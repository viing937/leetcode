impl Solution {
    #[allow(dead_code)]
    pub fn ones_minus_zeros(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (grid.len(), grid[0].len());

        let mut ones_row = vec![0; m];
        let mut ones_col = vec![0; n];

        for (i, row) in grid.iter().enumerate() {
            for (j, &num) in row.iter().enumerate() {
                ones_row[i] += num;
                ones_col[j] += num;
            }
        }

        let mut rslt = vec![vec![0; n]; m];
        for (i, row) in rslt.iter_mut().enumerate() {
            for (j, num) in row.iter_mut().enumerate() {
                *num = 2 * (ones_row[i] + ones_col[j]) - m as i32 - n as i32;
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
