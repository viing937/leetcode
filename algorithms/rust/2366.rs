impl Solution {
    #[allow(dead_code)]
    pub fn minimum_replacement(nums: Vec<i32>) -> i64 {
        let mut last = *nums.last().unwrap();
        let mut rslt = 0;

        for &num in nums.iter().rev().skip(1) {
            if num > last {
                let splits = (num - 1) / last;
                rslt += splits as i64;
                last = num / (splits + 1);
            } else {
                last = num;
            }
        }

        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
