use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        let mut char_count = HashMap::new();
        for ch in chars.bytes() {
            *char_count.entry(ch).or_insert(0) += 1;
        }

        let mut rslt = 0;
        for word in words {
            let mut word_char = HashMap::new();
            for ch in word.bytes() {
                *word_char.entry(ch).or_insert(0) += 1;
            }

            let mut is_good = true;
            for (ch, cnt) in word_char {
                if cnt > *char_count.get(&ch).unwrap_or(&0) {
                    is_good = false;
                }
            }
            if is_good {
                rslt += word.len() as i32;
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
