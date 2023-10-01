impl Solution {
    #[allow(dead_code)]
    pub fn reverse_words(s: String) -> String {
        s.split_whitespace()
            .map(|s| s.chars().rev().collect::<String>())
            .collect::<Vec<String>>()
            .join(" ")
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
