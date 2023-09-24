use std::mem;

impl Solution {
    #[allow(dead_code)]
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
        let mut row = vec![poured as f64];
        for _ in 0..query_row {
            let mut new_row = vec![0.0; row.len() + 1];
            for j in 0..row.len() {
                if row[j] > 1.0 {
                    let fall = (row[j] - 1.0) / 2.0;
                    new_row[j] += fall;
                    new_row[j + 1] += fall;
                }
            }
            mem::swap(&mut row, &mut new_row);
        }
        row[query_glass as usize].min(1.0)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
