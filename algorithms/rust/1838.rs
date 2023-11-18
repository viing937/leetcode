impl Solution {
    #[allow(dead_code)]
    pub fn max_frequency(mut nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        nums.sort();

        let (mut left, mut right) = (0, 0);
        let mut sum = nums[0] as usize;
        let mut rslt = 1;

        while right + 1 < nums.len() {
            right += 1;
            sum += nums[right] as usize;

            while (right - left + 1) * nums[right] as usize - sum > k {
                sum -= nums[left] as usize;
                left += 1;
            }

            rslt = rslt.max(right - left + 1);
        }
        rslt as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
