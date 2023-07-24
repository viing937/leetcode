impl Solution {
    #[allow(unused)]
    pub fn edge_score(edges: Vec<i32>) -> i32 {
        let n = edges.len();
        let mut scores = vec![0; n];
        for (i, edge) in edges.into_iter().enumerate() {
            scores[edge as usize] += i;
        }
        scores
            .iter()
            .enumerate()
            .min_by(|(_, a), (_, b)| b.cmp(a))
            .map(|(i, _)| i)
            .unwrap() as i32
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
