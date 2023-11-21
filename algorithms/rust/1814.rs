use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn count_nice_pairs(nums: Vec<i32>) -> i32 {
        let mod_: i64 = 1_000_000_000 + 7;
        let mut diff_cnt = HashMap::new();
        for n in nums {
            let rev_n = Self::rev(n);
            *diff_cnt.entry(n - rev_n).or_insert(0) += 1;
        }
        let mut rslt = 0;
        for cnt in diff_cnt.values() {
            rslt = (rslt + cnt * (cnt - 1) / 2) % mod_;
        }
        rslt as i32
    }

    fn rev(mut n: i32) -> i32 {
        let mut rslt = 0;
        while n != 0 {
            rslt = rslt * 10 + n % 10;
            n /= 10;
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
