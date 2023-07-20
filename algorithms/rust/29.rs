impl Solution {
    #[allow(unused)]
    pub fn divide(dividend: i32, divisor: i32) -> i32 {
        if dividend == i32::MIN && divisor == -1 {
            return i32::MAX;
        }
        let neg = (dividend ^ divisor) < 0;
        let mut dividend = dividend.unsigned_abs();
        let divisor = divisor.unsigned_abs();

        let mut quotient = 0;
        for i in (0..32).rev() {
            if ((dividend >> i) >= divisor) {
                quotient += 1 << i;
                dividend -= divisor << i;
            }
        }
        return if neg { -quotient } else { quotient };
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
