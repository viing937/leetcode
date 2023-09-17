use std::collections::{HashSet, VecDeque};

impl Solution {
    #[allow(dead_code)]
    pub fn shortest_path_length(graph: Vec<Vec<i32>>) -> i32 {
        let n = graph.len();
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        for i in 0..n {
            queue.push_back((1 << i, i, 0));
            visited.insert((1 << i, i));
        }
        while let Some((mask, node, dis)) = queue.pop_front() {
            if mask == (1 << n) - 1 {
                return dis;
            }
            for &next_node in graph[node].iter() {
                let new_mask = mask | (1 << next_node);
                if visited.insert((new_mask, next_node as usize)) {
                    queue.push_back((new_mask, next_node as usize, dis + 1));
                }
            }
        }
        0
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
