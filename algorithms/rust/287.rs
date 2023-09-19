impl Solution {
    #[allow(dead_code)]
    pub fn find_duplicate(mut nums: Vec<i32>) -> i32 {
        let n = nums.len() - 1;
        for i in 1..=n {
            while nums[i] != i as i32 {
                let t = nums[i] as usize;
                if nums[i] == nums[t] {
                    return nums[i];
                }
                nums[i] = nums[t];
                nums[t] = t as i32;
            }
        }
        nums[0]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
