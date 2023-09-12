use std::{cmp, collections::HashMap};

impl Solution {
    #[allow(dead_code)]
    pub fn min_deletions(s: String) -> i32 {
        let mut cnt_map = HashMap::new();
        for ch in s.chars() {
            *cnt_map.entry(ch).or_insert(0) += 1;
        }

        let mut cnt_list: Vec<_> = cnt_map.into_values().collect();
        cnt_list.sort_by_key(|&x| cmp::Reverse(x));

        let mut rslt = 0;
        let mut last_cnt = cnt_list[0];

        for cnt in cnt_list.into_iter().skip(1) {
            if last_cnt == 0 {
                rslt += cnt;
            } else if cnt >= last_cnt {
                rslt += cnt - last_cnt + 1;
                last_cnt -= 1;
            } else {
                last_cnt = cnt;
            }
        }

        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
