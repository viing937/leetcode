impl Solution {
    #[allow(dead_code)]
    pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
        let n = nums.len();
        let mut pre_sum = vec![0; n + 1];
        for i in 0..n {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }
        let mut rslt = i32::MAX;
        for i in 0..=n {
            if pre_sum[i] > x {
                break;
            }
            let target = x - pre_sum[i];
            let (mut left, mut right) = (i as i32, n as i32);
            while left <= right {
                let mid = (right - left) / 2 + left;
                match target.cmp(&(pre_sum[n] - pre_sum[mid as usize])) {
                    std::cmp::Ordering::Equal => {
                        rslt = rslt.min(i as i32 + n as i32 - mid);
                        break;
                    }
                    std::cmp::Ordering::Less => left = mid + 1,
                    std::cmp::Ordering::Greater => right = mid - 1,
                }
            }
        }
        if rslt == i32::MAX {
            -1
        } else {
            rslt
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
