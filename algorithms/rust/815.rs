use std::{
    cmp,
    collections::{BinaryHeap, HashSet},
};

impl Solution {
    #[allow(dead_code)]
    pub fn num_buses_to_destination(routes: Vec<Vec<i32>>, source: i32, target: i32) -> i32 {
        if source == target {
            return 0;
        }
        let routes: Vec<HashSet<i32>> = routes
            .into_iter()
            .map(|v| v.into_iter().collect())
            .collect();
        let n = routes.len();
        let mut dis = vec![i32::MAX; n];
        let mut pq = BinaryHeap::new();

        for i in 0..n {
            if routes[i].contains(&source) {
                dis[i] = 1;
                pq.push((cmp::Reverse(1), i));
            }
        }

        while let Some((cmp::Reverse(current_dis), r)) = pq.pop() {
            dis[r] = current_dis;

            if routes[r].contains(&target) {
                return current_dis;
            }

            for i in 0..n {
                if routes[i].intersection(&routes[r]).next().is_some() && dis[i] > current_dis + 1 {
                    pq.push((cmp::Reverse(current_dis + 1), i));
                }
            }
        }

        -1
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
