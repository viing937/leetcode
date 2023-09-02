use std::collections::HashMap;

pub struct Trie {
    is_word: bool,
    children: HashMap<char, Box<Trie>>,
}

impl Trie {
    fn new() -> Self {
        Self {
            is_word: false,
            children: HashMap::new(),
        }
    }

    fn add(&mut self, word: &str) {
        let mut t = self;
        for ch in word.chars() {
            t = t.children.entry(ch).or_insert(Box::new(Self::new()));
        }
        t.is_word = true;
    }

    fn check(&self, word: &str) -> bool {
        let mut t = self;
        for ch in word.chars() {
            match t.children.get(&ch) {
                Some(node) => {
                    t = node;
                }
                None => return false,
            }
        }
        t.is_word
    }
}

impl Solution {
    #[allow(dead_code)]
    pub fn min_extra_char(s: String, dictionary: Vec<String>) -> i32 {
        let mut trie = Trie::new();
        for word in dictionary {
            trie.add(&word);
        }

        let n = s.len();
        let mut dp: Vec<usize> = (0..=n).collect();
        for i in 1..=n {
            dp[i] = dp[i - 1] + 1;
            for j in 0..i {
                if trie.check(&s[j..i]) {
                    dp[i] = dp[i].min(dp[j]);
                }
            }
        }
        dp[n] as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
