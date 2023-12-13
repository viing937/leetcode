impl Solution {
    #[allow(dead_code)]
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (mat.len(), mat[0].len());
        let mut sum_row = vec![0; m];
        let mut sum_col = vec![0; n];
        for (i, row) in mat.iter().enumerate() {
            for (j, num) in row.iter().enumerate() {
                sum_row[i] += num;
                sum_col[j] += num;
            }
        }

        let mut rslt = 0;
        for (i, row) in mat.iter().enumerate() {
            for (j, &num) in row.iter().enumerate() {
                if num == 1 && sum_row[i] == 1 && sum_col[j] == 1 {
                    rslt += 1;
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
