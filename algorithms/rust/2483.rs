impl Solution {
    #[allow(dead_code)]
    pub fn best_closing_time(customers: String) -> i32 {
        let n = customers.len();
        let mut pre_sum = vec![0; n + 1];

        for (idx, ch) in customers.chars().enumerate() {
            pre_sum[idx + 1] += pre_sum[idx] + if ch == 'Y' { 1 } else { 0 };
        }
        let mut p_min = pre_sum[n];
        let mut hour = 0;

        for i in 1..=n {
            let p_left = i - pre_sum[i];
            let p_right = pre_sum[n] - pre_sum[i];
            if p_min > p_left + p_right {
                p_min = p_left + p_right;
                hour = i;
            }
        }

        hour as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
