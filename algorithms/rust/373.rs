use std::{cmp::Reverse, collections::BinaryHeap};

impl Solution {
    #[allow(unused)]
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let mut heap = BinaryHeap::new();
        for i in 0..nums1.len() {
            heap.push((Reverse(nums1[i] + nums2[0]), i, 0));
        }

        let mut pairs = Vec::new();
        for i in 0..k {
            match heap.pop() {
                Some((sum, idx1, idx2)) => {
                    pairs.push(vec![nums1[idx1], nums2[idx2]]);
                    if idx2 + 1 < nums2.len() {
                        heap.push((Reverse(nums1[idx1] + nums2[idx2 + 1]), idx1, idx2 + 1));
                    }
                }
                None => break,
            }
        }
        return pairs;
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
