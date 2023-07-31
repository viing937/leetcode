impl Solution {
    #[allow(unused)]
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }
        x == Self::reverse(x)
    }

    fn reverse(mut x: i32) -> i32 {
        let mut r = 0;
        while x > 0 {
            r = r * 10 + x % 10;
            x /= 10;
        }
        r
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
