impl Solution {
    #[allow(unused)]
    pub fn is_palindrome(s: String) -> bool {
        let s: Vec<char> = s
            .to_lowercase()
            .chars()
            .filter(|ch| ch.is_alphanumeric())
            .collect();
        s.iter()
            .enumerate()
            .zip(s.iter().enumerate().rev())
            .take_while(|((idx_a, _), (idx_b, _))| idx_a < idx_b)
            .all(|((_, ch_a), (_, ch_b))| ch_a == ch_b)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
