struct UnionFind {
    parent: Vec<usize>,
}

impl UnionFind {
    pub fn new(n: usize) -> Self {
        UnionFind {
            parent: (0..n).collect::<Vec<usize>>(),
        }
    }

    pub fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }

    pub fn union(&mut self, x: usize, y: usize) -> bool {
        let x_root = self.find(x);
        let y_root = self.find(y);
        if x_root == y_root {
            return false;
        }
        self.parent[x_root] = y_root;
        true
    }
}

impl Solution {
    #[allow(dead_code)]
    pub fn min_cost_connect_points(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut edges = vec![];
        for i in 0..n {
            for j in i + 1..n {
                let dis = (points[i][0] - points[j][0]).abs() + (points[i][1] - points[j][1]).abs();
                edges.push((i, j, dis));
            }
        }

        edges.sort_by(|x, y| x.2.cmp(&y.2));

        let mut union_find = UnionFind::new(n);
        let mut cost = 0;
        for e in edges {
            if union_find.union(e.0, e.1) {
                cost += e.2;
            }
        }

        cost
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
