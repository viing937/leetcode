impl Solution {
    #[allow(unused)]
    pub fn check_x_matrix(grid: Vec<Vec<i32>>) -> bool {
        let n = grid.len();
        for (i, row) in grid.into_iter().enumerate() {
            for (j, item) in row.into_iter().enumerate() {
                if i == j || i + j == n - 1 {
                    if item == 0 {
                        return false;
                    }
                } else if item != 0 {
                    return false;
                }
            }
        }
        true
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
