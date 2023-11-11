use std::{
    cmp,
    collections::{BinaryHeap, HashMap},
};

struct Graph {
    n: usize,
    g: HashMap<usize, HashMap<usize, i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Graph {
    #[allow(dead_code)]
    fn new(n: i32, edges: Vec<Vec<i32>>) -> Self {
        let mut graph = Self {
            n: n as usize,
            g: HashMap::new(),
        };
        for edge in edges {
            graph.add_edge(edge);
        }
        graph
    }

    #[allow(dead_code)]
    fn add_edge(&mut self, edge: Vec<i32>) {
        let (from, to, cost) = (edge[0] as usize, edge[1] as usize, edge[2]);
        self.g.entry(from).or_default().entry(to).or_insert(cost);
    }

    #[allow(dead_code)]
    fn shortest_path(&self, node1: i32, node2: i32) -> i32 {
        let (start, end) = (node1 as usize, node2 as usize);
        let mut dis = vec![i32::MAX; self.n];
        dis[start] = 0;

        let mut pq = BinaryHeap::new();
        pq.push((cmp::Reverse(0), start));

        while let Some((cmp::Reverse(current_cost), current_node)) = pq.pop() {
            if current_cost > dis[current_node] {
                continue;
            }

            if current_node == end {
                return current_cost;
            }

            for (&neighbor, &cost) in self.g.get(&current_node).unwrap_or(&HashMap::new()).iter() {
                let new_cost = dis[current_node] + cost;
                if new_cost < dis[neighbor] {
                    dis[neighbor] = new_cost;
                    pq.push((cmp::Reverse(new_cost), neighbor));
                }
            }
        }
        if dis[end] == i32::MAX {
            -1
        } else {
            dis[end]
        }
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * let obj = Graph::new(n, edges);
 * obj.add_edge(edge);
 * let ret_2: i32 = obj.shortest_path(node1, node2);
 */

fn main() {
    println!("Hello, world!");
}
