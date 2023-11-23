impl Solution {
    #[allow(dead_code)]
    pub fn check_arithmetic_subarrays(nums: Vec<i32>, l: Vec<i32>, r: Vec<i32>) -> Vec<bool> {
        let mut rslt = vec![];
        for (&left, &right) in l.iter().zip(r.iter()) {
            let (left, right) = (left as usize, right as usize);
            let mut sub_array: Vec<_> = nums.iter().skip(left).take(right - left + 1).collect();
            sub_array.sort();
            if sub_array.len() <= 1 {
                rslt.push(true);
                continue;
            }
            let diff = sub_array[1] - sub_array[0];
            let mut is_arithmetic = true;
            for i in 1..sub_array.len() {
                if sub_array[i] - sub_array[i - 1] != diff {
                    is_arithmetic = false;
                    break;
                }
            }
            rslt.push(is_arithmetic);
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
