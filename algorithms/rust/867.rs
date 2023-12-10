impl Solution {
    #[allow(dead_code)]
    pub fn transpose(matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (matrix.len(), matrix[0].len());
        let mut rslt = vec![vec![0; m]; n];
        for (i, row) in matrix.iter().enumerate() {
            for (j, num) in row.iter().enumerate() {
                rslt[j][i] = *num;
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
