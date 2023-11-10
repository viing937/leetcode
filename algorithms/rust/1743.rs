use std::{collections::HashMap, mem};

impl Solution {
    #[allow(dead_code)]
    pub fn restore_array(adjacent_pairs: Vec<Vec<i32>>) -> Vec<i32> {
        let mut adjacent_dict = HashMap::new();
        for pair in adjacent_pairs {
            let (first, second) = (pair[0], pair[1]);
            adjacent_dict.entry(first).or_insert(vec![]).push(second);
            adjacent_dict.entry(second).or_insert(vec![]).push(first);
        }

        let mut rslt = vec![];

        for (&key, items) in adjacent_dict.iter() {
            if items.len() == 1 {
                rslt.push(key);
                rslt.push(items[0]);
                break;
            }
        }

        let (mut first, mut second) = (rslt[0], rslt[1]);
        while let Some(adjacent_items) = adjacent_dict.get(&second) {
            if adjacent_items.len() == 1 {
                break;
            }
            first = if first == adjacent_items[0] {
                adjacent_items[1]
            } else {
                adjacent_items[0]
            };
            mem::swap(&mut first, &mut second);
            rslt.push(second);
        }

        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
