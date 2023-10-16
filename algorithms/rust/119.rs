impl Solution {
    #[allow(dead_code)]
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut last_row = vec![1];
        for _ in 0..row_index {
            let mut row = vec![1; last_row.len() + 1];
            for i in 1..last_row.len() {
                row[i] = last_row[i - 1] + last_row[i];
            }
            last_row = row;
        }
        last_row
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
