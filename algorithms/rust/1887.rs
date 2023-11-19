impl Solution {
    #[allow(dead_code)]
    pub fn reduction_operations(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let (mut rslt, mut last_num) = (0, nums.last().unwrap());
        for (i, num) in nums.iter().rev().enumerate() {
            if num != last_num {
                rslt += i as i32;
            }
            last_num = num;
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
