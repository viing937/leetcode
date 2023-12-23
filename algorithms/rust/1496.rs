use std::collections::{HashMap, HashSet};

impl Solution {
    #[allow(dead_code)]
    pub fn is_path_crossing(path: String) -> bool {
        let dx_map: HashMap<char, i32> = [('N', 0), ('S', 0), ('E', 1), ('W', -1)]
            .iter()
            .cloned()
            .collect();
        let dy_map: HashMap<char, i32> = [('N', 1), ('S', -1), ('E', 0), ('W', 0)]
            .iter()
            .cloned()
            .collect();
        let (mut cur_x, mut cur_y) = (0, 0);
        let mut visited: HashSet<(i32, i32)> = HashSet::new();
        visited.insert((cur_x, cur_y));

        for ch in path.chars() {
            let dx = dx_map.get(&ch).unwrap();
            let dy = dy_map.get(&ch).unwrap();
            cur_x += dx;
            cur_y += dy;
            if visited.contains(&(cur_x, cur_y)) {
                return true;
            } else {
                visited.insert((cur_x, cur_y));
            }
        }
        false
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
