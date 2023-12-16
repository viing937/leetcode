use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn is_anagram(s: String, t: String) -> bool {
        Self::count_char(s) == Self::count_char(t)
    }

    fn count_char(s: String) -> HashMap<u8, usize> {
        let mut cnt = HashMap::new();
        for ch in s.bytes() {
            *cnt.entry(ch).or_insert(0) += 1;
        }
        cnt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
