use std::mem;

impl Solution {
    #[allow(dead_code)]
    pub fn find_median_sorted_arrays(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> f64 {
        if nums1.len() > nums2.len() {
            mem::swap(&mut nums1, &mut nums2)
        }

        let (m, n) = (nums1.len(), nums2.len());
        let (mut left, mut right) = (0, m);

        while left <= right {
            let p_x = (right - left) / 2 + left;
            let p_y = (m + n + 1) / 2 - p_x;

            let max_x = if p_x == 0 {
                f64::MIN
            } else {
                nums1[p_x - 1] as f64
            };
            let min_x = if p_x == m {
                f64::MAX
            } else {
                nums1[p_x] as f64
            };
            let max_y = if p_y == 0 {
                f64::MIN
            } else {
                nums2[p_y - 1] as f64
            };
            let min_y = if p_y == n {
                f64::MAX
            } else {
                nums2[p_y] as f64
            };

            if max_x <= min_y && max_y <= min_x {
                if (m + n) % 2 == 0 {
                    return (max_x.max(max_y) + min_x.min(min_y)) / 2.0;
                } else {
                    return max_x.max(max_y);
                }
            } else if max_x > min_y {
                right = p_x - 1;
            } else {
                left = p_x + 1;
            }
        }
        0.0
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
