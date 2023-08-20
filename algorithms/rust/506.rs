use std::cmp::Reverse;

impl Solution {
    #[allow(dead_code)]
    pub fn find_relative_ranks(score: Vec<i32>) -> Vec<String> {
        let mut score: Vec<(usize, i32)> = score
            .into_iter()
            .enumerate()
            .map(|(idx, s)| (idx, s))
            .collect();
        score.sort_by_key(|x| Reverse(x.1));

        let mut rslt = vec!["".to_owned(); score.len()];
        for (place, item) in score.into_iter().enumerate() {
            let idx = item.0;
            match place {
                0 => rslt[idx] = "Gold Medal".to_owned(),
                1 => rslt[idx] = "Silver Medal".to_owned(),
                2 => rslt[idx] = "Bronze Medal".to_owned(),
                _ => rslt[idx] = format!("{}", place + 1),
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
