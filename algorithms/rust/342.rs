impl Solution {
    #[allow(dead_code)]
    pub fn is_power_of_four(mut n: i32) -> bool {
        if n <= 0 {
            return false;
        }
        while n % 4 == 0 {
            n /= 4;
        }
        n == 1
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
