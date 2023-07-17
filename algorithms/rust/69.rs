impl Solution {
    #[allow(unused)]
    pub fn my_sqrt(x: i32) -> i32 {
        let x = x as f64;
        let mut x1 = 1.0;
        let mut x2 = (x1 + x / x1) / 2.0;
        while (x1 - x2).abs() > 0.1 {
            x1 = x2;
            x2 = (x1 + x / x1) / 2.0;
        }
        return x2 as i32;
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
