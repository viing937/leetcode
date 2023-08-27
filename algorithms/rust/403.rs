use std::collections::{HashSet, VecDeque};

impl Solution {
    #[allow(dead_code)]
    pub fn can_cross(stones: Vec<i32>) -> bool {
        let stones: Vec<_> = stones.into_iter().map(|x| x as usize).collect();

        if stones[1] != 1 {
            return false;
        }

        let mut paths = VecDeque::new();
        paths.push_back((stones[1], 1_usize));
        let mut visited = HashSet::new();
        visited.insert((stones[1], 1_usize));

        while let Some(path) = paths.pop_front() {
            let (current, step) = path;

            if Some(&current) == stones.last() {
                return true;
            }

            let (min, max) = (1.max(step - 1), step + 1);
            (min..=max)
                .filter(|&x| stones.binary_search(&(current + x)).is_ok())
                .for_each(|x| {
                    let path = (current + x, x);
                    if !visited.contains(&path) {
                        visited.insert(path);
                        paths.push_back(path);
                    }
                })
        }

        false
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
