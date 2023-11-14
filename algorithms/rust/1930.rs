use std::collections::{HashMap, HashSet};

impl Solution {
    #[allow(dead_code)]
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let s = s.as_bytes();
        let (mut first, mut last) = (HashMap::new(), HashMap::new());
        for (idx, &ch) in s.iter().enumerate() {
            first.entry(ch).or_insert(idx);
            *last.entry(ch).or_insert(idx) = idx;
        }
        let mut rslt = 0;
        for c in b'a'..=b'z' {
            if let Some(&start) = first.get(&c) {
                if let Some(&end) = last.get(&c) {
                    let mut counted = HashSet::new();
                    for &mid in s.iter().take(end).skip(start + 1) {
                        if !counted.contains(&mid) {
                            counted.insert(mid);
                            rslt += 1;
                        }
                    }
                }
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
