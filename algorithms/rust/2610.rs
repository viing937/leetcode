use std::{cmp, collections::HashMap};

impl Solution {
    #[allow(dead_code)]
    pub fn find_matrix(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut num_cnt = HashMap::new();
        for num in nums {
            *num_cnt.entry(num).or_insert(0) += 1;
        }
        let mut num_cnt: Vec<(cmp::Reverse<usize>, i32)> = num_cnt
            .iter()
            .map(|(&num, &cnt)| (cmp::Reverse(cnt), num))
            .collect();

        num_cnt.sort();
        let rows = num_cnt[0].0 .0;
        let mut rslt = vec![vec![]; rows];
        for (cmp::Reverse(cnt), num) in num_cnt {
            (0..cnt).for_each(|i| {
                rslt[i].push(num);
            });
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
