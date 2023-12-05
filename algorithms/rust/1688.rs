impl Solution {
    #[allow(dead_code)]
    pub fn number_of_matches(mut n: i32) -> i32 {
        let mut rslt = 0;
        while n > 1 {
            rslt += n / 2;
            n = (n + 1) / 2;
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
