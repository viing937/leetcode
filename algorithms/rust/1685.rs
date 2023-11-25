impl Solution {
    #[allow(dead_code)]
    pub fn get_sum_absolute_differences(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut nums_with_idx: Vec<_> = nums
            .into_iter()
            .enumerate()
            .map(|(idx, num)| (num, idx))
            .collect();
        nums_with_idx.sort();

        let mut pre_sum = vec![];
        for (num, _) in nums_with_idx.iter() {
            pre_sum.push(pre_sum.last().unwrap_or(&0) + num);
        }

        let mut rslt = vec![0; n];
        for (idx, (num, origin_idx)) in nums_with_idx.iter().enumerate() {
            let diff_less = num * (idx + 1) as i32 - pre_sum[idx];
            let diff_more = pre_sum.last().unwrap() - pre_sum[idx] - num * (n - idx - 1) as i32;
            rslt[*origin_idx] = diff_less + diff_more;
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
