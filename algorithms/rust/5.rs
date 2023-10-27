impl Solution {
    #[allow(dead_code)]
    pub fn longest_palindrome(s: String) -> String {
        let sb = s.as_bytes();
        let (mut left, mut right) = (0, 0);
        for c in 0..s.len() {
            let (mut l, mut r) = (c, c);
            while l >= 1 && r < s.len() - 1 && sb[l - 1] == sb[r + 1] {
                l -= 1;
                r += 1;
            }
            if r - l > right - left {
                left = l;
                right = r;
            }
        }
        for c in 1..s.len() {
            if sb[c - 1] != sb[c] {
                continue;
            }
            let (mut l, mut r) = (c - 1, c);
            while l >= 1 && r < s.len() - 1 && sb[l - 1] == sb[r + 1] {
                l -= 1;
                r += 1;
            }
            if r - l > right - left {
                left = l;
                right = r;
            }
        }
        s[left..=right].to_string()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
