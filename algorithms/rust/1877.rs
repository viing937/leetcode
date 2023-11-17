impl Solution {
    #[allow(dead_code)]
    pub fn min_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut rslt = i32::MIN;

        let n = nums.len();
        for (a, b) in nums.iter().skip(n / 2).zip(nums.iter().rev().skip(n / 2)) {
            rslt = rslt.max(a + b);
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
