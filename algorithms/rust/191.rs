impl Solution {
    #[allow(dead_code, non_snake_case)]
    pub fn hammingWeight(mut n: u32) -> i32 {
        let mut rslt = 0;
        while n > 0 {
            rslt += n % 2;
            n /= 2;
        }
        rslt as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
