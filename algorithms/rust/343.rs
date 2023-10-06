impl Solution {
    #[allow(dead_code)]
    pub fn integer_break(mut n: i32) -> i32 {
        if n == 2 {
            return 1;
        } else if n == 3 {
            return 2;
        }

        let mut product = 1;
        if n % 2 == 1 && n >= 3 {
            n -= 3;
            product *= 3;
        }

        product *= 9_i32.pow(n as u32 / 6);
        n %= 6;

        product *= 2_i32.pow(n as u32 / 2);

        product
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
