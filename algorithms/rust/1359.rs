impl Solution {
    #[allow(dead_code)]
    pub fn count_orders(n: i32) -> i32 {
        let n = n as usize;
        let mod_ = 1_000_000_000 + 7;
        let mut dp = 1;

        for i in 0..n {
            dp = ((i + 1) * (2 * i + 1) * dp) % mod_;
        }
        dp as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
