use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut char_cnt: HashMap<char, i32> = HashMap::new();
        for ch in s.chars() {
            *char_cnt.entry(ch).or_insert(0) += 1;
        }
        for ch in t.chars() {
            *char_cnt.entry(ch).or_insert(0) -= 1;
        }
        char_cnt.into_values().filter(|&cnt| cnt > 0).sum()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
