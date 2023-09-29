impl Solution {
    #[allow(dead_code)]
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        if nums.len() <= 1 {
            return true;
        }
        let dir = nums.first().unwrap().cmp(nums.last().unwrap());
        for (a, b) in nums.iter().zip(nums.iter().skip(1)) {
            if a != b && a.cmp(b) != dir {
                return false;
            }
        }
        true
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
