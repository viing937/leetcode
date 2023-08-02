use std::collections::{HashMap, HashSet};

impl Solution {
    #[allow(unused)]
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        let morse_code = HashMap::from([
            ('a', String::from(".-")),
            ('b', String::from("-...")),
            ('c', String::from("-.-.")),
            ('d', String::from("-..")),
            ('e', String::from(".")),
            ('f', String::from("..-.")),
            ('g', String::from("--.")),
            ('h', String::from("....")),
            ('i', String::from("..")),
            ('j', String::from(".---")),
            ('k', String::from("-.-")),
            ('l', String::from(".-..")),
            ('m', String::from("--")),
            ('n', String::from("-.")),
            ('o', String::from("---")),
            ('p', String::from(".--.")),
            ('q', String::from("--.-")),
            ('r', String::from(".-.")),
            ('s', String::from("...")),
            ('t', String::from("-")),
            ('u', String::from("..-")),
            ('v', String::from("...-")),
            ('w', String::from(".--")),
            ('x', String::from("-..-")),
            ('y', String::from("-.--")),
            ('z', String::from("--..")),
        ]);

        let mut morsed: HashSet<String> = HashSet::new();
        for word in words.iter() {
            morsed.insert(
                word.chars()
                    .map(|ch| morse_code.get(&ch).unwrap().clone())
                    .collect(),
            );
        }
        morsed.len() as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
