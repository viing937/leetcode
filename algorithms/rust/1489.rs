struct UnionFind {
    parent: Vec<usize>,
    size: Vec<usize>,
    max_size: usize,
}

impl UnionFind {
    pub fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect::<Vec<usize>>(),
            size: vec![1; n],
            max_size: 1,
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
        self.size[y_root] += self.size[x_root];
        self.max_size = self.max_size.max(self.size[y_root]);
        true
    }
}

impl Solution {
    #[allow(dead_code)]
    pub fn find_critical_and_pseudo_critical_edges(n: i32, edges: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = n as usize;
        let mut edges: Vec<_> = edges
            .into_iter()
            .enumerate()
            .map(|(idx, edge)| {
                (
                    edge[0] as usize,
                    edge[1] as usize,
                    edge[2] as usize,
                    idx as i32,
                )
            })
            .collect();
        edges.sort_by_key(|edge| edge.2);

        let mut min_weight = 0;
        let mut union_find = UnionFind::new(n);
        for edge in edges.iter() {
            let (x, y, weight) = (edge.0, edge.1, edge.2);
            if union_find.union(x, y) {
                min_weight += weight;
            }
        }

        let mut rslt = vec![vec![]; 2];
        for i in 0..edges.len() {
            let mut min_weight_without_i = 0;
            let mut union_find = UnionFind::new(n);
            for (j, edge) in edges.iter().enumerate() {
                if i == j {
                    continue;
                }
                let (x, y, weight) = (edge.0, edge.1, edge.2);
                if union_find.union(x, y) {
                    min_weight_without_i += weight;
                }
            }

            if min_weight_without_i > min_weight || union_find.max_size < n {
                rslt[0].push(edges[i].3);
                continue;
            }

            let mut min_weight_with_i = edges[i].2;
            let mut union_find = UnionFind::new(n);
            union_find.union(edges[i].0, edges[i].1);
            for (j, edge) in edges.iter().enumerate() {
                if i == j {
                    continue;
                }
                let (x, y, weight) = (edge.0, edge.1, edge.2);
                if union_find.union(x, y) {
                    min_weight_with_i += weight;
                }
            }

            if min_weight_with_i == min_weight {
                rslt[1].push(edges[i].3);
            }
        }

        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
