impl Solution {
    #[allow(dead_code)]
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let num_rows = num_rows as usize;
        let mut triangle = vec![vec![1]];

        for i in 2..=num_rows {
            let last_row = triangle.last().unwrap();
            let mut row = vec![1; i];
            for j in 1..i - 1 {
                row[j] = last_row[j - 1] + last_row[j];
            }
            triangle.push(row);
        }

        triangle
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
