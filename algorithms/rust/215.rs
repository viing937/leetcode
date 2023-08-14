use std::cmp::Ordering;

impl Solution {
    #[allow(dead_code)]
    pub fn find_kth_largest(mut nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        Self::binary(&mut nums, 0, n - 1, k as usize)
    }

    fn binary(nums: &mut Vec<i32>, left: usize, right: usize, k: usize) -> i32 {
        let pivot = nums[left];

        let (mut low, mut high) = (left, right);
        while low < high {
            while low < high && nums[high] <= pivot {
                high -= 1;
            }
            nums[low] = nums[high];
            while low < high && nums[low] > pivot {
                low += 1;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        match (left + k - 1).cmp(&low) {
            Ordering::Less => Self::binary(nums, left, low - 1, k),
            Ordering::Greater => Self::binary(nums, low + 1, right, k - (low - left + 1)),
            Ordering::Equal => nums[low],
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
