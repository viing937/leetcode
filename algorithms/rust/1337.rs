impl Solution {
    #[allow(dead_code)]
    pub fn k_weakest_rows(mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut rows: Vec<(i32, i32)> = mat
            .iter()
            .enumerate()
            .map(|(idx, row)| (row.iter().sum(), idx as i32))
            .collect();
        rows.sort();
        rows.iter().take(k as usize).map(|(_, idx)| *idx).collect()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
