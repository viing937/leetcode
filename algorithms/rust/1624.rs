use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        let mut first: HashMap<char, usize> = HashMap::new();
        let mut last: HashMap<char, usize> = HashMap::new();
        for (i, ch) in s.chars().enumerate() {
            first.entry(ch).or_insert(i);
            last.insert(ch, i);
        }
        let mut rslt: i32 = -1;
        for ch in first.keys() {
            let start = first.get(ch).unwrap();
            let end = last.get(ch).unwrap();
            if start != end {
                rslt = rslt.max((end - start - 1) as i32);
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
