use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn make_equal(words: Vec<String>) -> bool {
        let n = words.len();
        let mut ch_counter: HashMap<char, usize> = HashMap::new();
        for word in words {
            for ch in word.chars() {
                *ch_counter.entry(ch).or_insert(0) += 1;
            }
        }

        for (_, cnt) in ch_counter {
            if cnt % n != 0 {
                return false;
            }
        }
        true
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
