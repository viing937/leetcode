use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut num_cnt: HashMap<i32, i32> = HashMap::new();
        for num in nums {
            *num_cnt.entry(num).or_insert(0) += 1;
        }
        let mut rslt = 0;
        for (_, cnt) in num_cnt {
            if cnt == 1 {
                return -1;
            }
            if cnt % 3 == 0 {
                rslt += cnt / 3;
            } else {
                rslt += cnt / 3 + 1;
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
