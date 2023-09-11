use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let mut groups: HashMap<i32, Vec<i32>> = HashMap::new();
        for (i, &size) in group_sizes.iter().enumerate() {
            groups.entry(size).or_insert(vec![]).push(i as i32);
        }

        let mut rslt = vec![];
        for (size, group_vec) in groups {
            let size = size as usize;
            rslt.append(
                group_vec
                    .chunks(size)
                    .map(|chunk| chunk.to_vec())
                    .collect::<Vec<Vec<_>>>()
                    .as_mut(),
            );
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
