use std::collections::HashSet;

impl Solution {
    #[allow(dead_code)]
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        let mut city_has_path = HashSet::new();
        for path in paths.iter() {
            city_has_path.insert(&path[0]);
        }
        for path in paths.iter() {
            if !city_has_path.contains(&path[1]) {
                return path[1].clone();
            }
        }
        "".to_owned()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
