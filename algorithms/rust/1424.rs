impl Solution {
    #[allow(dead_code)]
    pub fn find_diagonal_order(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut diagonal_array = vec![];
        for (i, arr) in nums.iter().enumerate() {
            for (j, &num) in arr.iter().enumerate() {
                let idx = i + j;
                if idx >= diagonal_array.len() {
                    diagonal_array.push(vec![]);
                }
                diagonal_array[idx].push(num);
            }
        }

        let mut rslt = vec![];
        for arr in diagonal_array {
            rslt.extend(arr.iter().rev());
        }

        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
