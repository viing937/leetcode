use std::collections::HashSet;

impl Solution {
    #[allow(unused)]
    pub fn buddy_strings(s: String, goal: String) -> bool {
        if s.len() != goal.len() {
            return false;
        }
        let candidate: Vec<_> = s
            .chars()
            .zip(goal.chars())
            .filter(|(a, b)| a != b)
            .collect();
        if candidate.is_empty() {
            let char_set: HashSet<char> = s.chars().collect();
            return char_set.len() < s.len();
        }
        if candidate.len() != 2 {
            return false;
        }
        candidate[0].0 == candidate[1].1 && candidate[1].0 == candidate[0].1
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
