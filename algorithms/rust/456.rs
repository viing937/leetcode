impl Solution {
    #[allow(dead_code)]
    pub fn find132pattern(nums: Vec<i32>) -> bool {
        let mut stack = vec![];
        let mut third = i32::MIN;
        for &num in nums.iter().rev() {
            if num < third {
                return true;
            }
            while let Some(&k) = stack.last() {
                if k >= num {
                    break;
                }
                third = k;
                stack.pop();
            }
            stack.push(num);
        }
        false
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
