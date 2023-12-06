impl Solution {
    #[allow(dead_code)]
    pub fn total_money(mut n: i32) -> i32 {
        let weeks = n / 7;
        n %= 7;

        (49 + 7 * weeks) * weeks / 2 + (weeks + 1 + weeks + n) * n / 2
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
