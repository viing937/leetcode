use std::collections::BinaryHeap;

impl Solution {
    #[allow(dead_code)]
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut heap = BinaryHeap::from(
            nums.iter()
                .take(k - 1)
                .enumerate()
                .map(|(idx, &val)| (val, idx))
                .collect::<Vec<(i32, usize)>>(),
        );
        let mut rslt = Vec::new();
        for (idx, &val) in nums.iter().enumerate().skip(k - 1) {
            heap.push((val, idx));
            while heap.peek().unwrap().1 < idx - k + 1 {
                heap.pop();
            }
            rslt.push(heap.peek().unwrap().0);
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
