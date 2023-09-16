use std::{cmp, collections::BinaryHeap};

impl Solution {
    #[allow(dead_code)]
    pub fn minimum_effort_path(heights: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (heights.len(), heights[0].len());
        let mut dist = vec![vec![i32::MAX; n]; m];
        dist[0][0] = 0;

        let mut pq = BinaryHeap::new();
        pq.push(cmp::Reverse((0, 0, 0)));

        let dxdy = [(-1, 0), (1, 0), (0, -1), (0, 1)];

        while let Some(cmp::Reverse((effort, x, y))) = pq.pop() {
            if effort > dist[x][y] {
                continue;
            }
            if x == m - 1 && y == n - 1 {
                break;
            }
            for (dx, dy) in dxdy {
                let nx = (x as i32 + dx) as usize;
                let ny = (y as i32 + dy) as usize;
                if nx < m && ny < n {
                    let new_effort = effort.max((heights[x][y] - heights[nx][ny]).abs());
                    if new_effort < dist[nx][ny] {
                        dist[nx][ny] = new_effort;
                        pq.push(cmp::Reverse((new_effort, nx, ny)));
                    }
                }
            }
        }

        dist[m - 1][n - 1]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
