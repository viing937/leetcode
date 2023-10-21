use std::collections::VecDeque;

impl Solution {
    #[allow(dead_code)]
    pub fn constrained_subset_sum(mut nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let mut window = VecDeque::new();
        for i in 0..nums.len() {
            if let Some(&max_value_idx) = window.front() {
                nums[i] += nums[max_value_idx];
            }
            while !window.is_empty() {
                if let Some(&first_idx) = window.front() {
                    if i - first_idx >= k {
                        window.pop_front();
                        continue;
                    }
                }
                if let Some(&last_idx) = window.back() {
                    if nums[i] > nums[last_idx] {
                        window.pop_back();
                        continue;
                    }
                }
                break;
            }
            if nums[i] > 0 {
                window.push_back(i);
            }
        }
        *nums.iter().max().unwrap()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
