use std::cmp::Ordering;

impl Solution {
    #[allow(dead_code)]
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let (m, n) = (matrix.len(), matrix[0].len());
        let mut left: i32 = 0;
        let mut right: i32 = (m * n - 1) as i32;
        while left <= right {
            let mid = left + (right - left) / 2;
            let val = matrix[mid as usize / n][mid as usize % n];
            match val.cmp(&target) {
                Ordering::Greater => {
                    right = mid - 1;
                }
                Ordering::Less => {
                    left = mid + 1;
                }
                _ => {
                    return true;
                }
            }
        }
        false
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
