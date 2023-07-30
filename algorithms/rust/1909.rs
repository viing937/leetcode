impl Solution {
    #[allow(unused)]
    pub fn can_be_increasing(nums: Vec<i32>) -> bool {
        let n = nums.len();
        for i in 1..n {
            if nums[i] <= nums[i - 1] {
                let mut t = nums[i].min(nums[i - 1]);
                if i >= 2 && t <= nums[i - 2] {
                    t = nums[i].max(nums[i - 1]);
                    if t <= nums[i - 2] {
                        return false;
                    }
                }
                if i + 1 < n && t >= nums[i + 1] {
                    return false;
                }
                for j in i + 1..nums.len() {
                    if nums[j] <= nums[j - 1] {
                        return false;
                    }
                }
            }
        }
        true
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
