use std::cmp::Ordering;

impl Solution {
    #[allow(dead_code)]
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        vec![
            Self::binary_search(&nums, target, true),
            Self::binary_search(&nums, target, false),
        ]
    }

    fn binary_search(nums: &Vec<i32>, target: i32, is_left: bool) -> i32 {
        let (mut left, mut right) = (0_i32, nums.len() as i32 - 1);
        let mut index = -1;
        while left <= right {
            let mid = left + (right - left) / 2;
            match nums[mid as usize].cmp(&target) {
                Ordering::Equal => {
                    index = mid;
                    if is_left {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                Ordering::Greater => right = mid - 1,
                Ordering::Less => left = mid + 1,
            }
        }
        index
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
