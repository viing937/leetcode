use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn validate_binary_tree_nodes(n: i32, left_child: Vec<i32>, right_child: Vec<i32>) -> bool {
        let mut parents = HashMap::new();
        for (_, &child) in left_child.iter().enumerate() {
            if child != -1 {
                *parents.entry(child).or_insert(0) += 1;
            }
        }
        for (_, &child) in right_child.iter().enumerate() {
            if child != -1 {
                *parents.entry(child).or_insert(0) += 1;
            }
        }
        let mut root_cnt = 0;
        let mut root = 0;
        for i in 0..n {
            match parents.get(&i) {
                None => {
                    root_cnt += 1;
                    root = i;
                }
                Some(&val) => {
                    if val > 1 {
                        return false;
                    }
                }
            }
        }
        if root_cnt != 1 {
            return false;
        }

        let mut stack = vec![root as usize];
        let mut visited = vec![false; n as usize];
        visited[root as usize] = true;

        while let Some(cur) = stack.pop() {
            if left_child[cur] != -1 {
                let child = left_child[cur] as usize;
                if visited[child] {
                    return false;
                } else {
                    visited[child] = true;
                    stack.push(child);
                }
            }
            if right_child[cur] != -1 {
                let child = right_child[cur] as usize;
                if visited[child] {
                    return false;
                } else {
                    visited[child] = true;
                    stack.push(child);
                }
            }
        }

        visited.iter().all(|x| *x)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
