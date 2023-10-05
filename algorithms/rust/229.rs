impl Solution {
    #[allow(dead_code)]
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let (mut num_1, mut cnt_1) = (0, 0);
        let (mut num_2, mut cnt_2) = (1, 0);
        for &num in nums.iter() {
            if num_1 == num {
                cnt_1 += 1;
            } else if num_2 == num {
                cnt_2 += 1;
            } else if cnt_1 == 0 {
                num_1 = num;
                cnt_1 = 1;
            } else if cnt_2 == 0 {
                num_2 = num;
                cnt_2 = 1;
            } else {
                cnt_1 -= 1;
                cnt_2 -= 1;
            }
        }
        let (mut cnt_1, mut cnt_2) = (0, 0);
        for &num in nums.iter() {
            if num == num_1 {
                cnt_1 += 1;
            } else if num == num_2 {
                cnt_2 += 1;
            }
        }
        let mut result = vec![];
        if cnt_1 > nums.len() / 3 {
            result.push(num_1);
        }
        if cnt_2 > nums.len() / 3 {
            result.push(num_2);
        }
        result
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
