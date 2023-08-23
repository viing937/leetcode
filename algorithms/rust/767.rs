use std::collections::{BinaryHeap, HashMap};

impl Solution {
    #[allow(dead_code)]
    pub fn reorganize_string(s: String) -> String {
        if s.is_empty() {
            return s;
        }

        let mut ch_cnt = HashMap::new();
        s.chars().for_each(|ch| *ch_cnt.entry(ch).or_insert(0) += 1);

        let mut heap = BinaryHeap::new();
        ch_cnt.iter().for_each(|(&ch, &cnt)| heap.push((cnt, ch)));

        let mut rslt = vec![];
        let mut first = heap.pop().unwrap();
        rslt.push(first.1);
        first.0 -= 1;

        while let Some(mut second) = heap.pop() {
            rslt.push(second.1);
            second.0 -= 1;
            if first.0 > 0 {
                heap.push(first);
            }
            first = second;
        }

        if first.0 > 0 {
            return "".to_owned();
        }

        rslt.iter().collect()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
