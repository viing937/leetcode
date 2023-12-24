impl Solution {
    #[allow(dead_code)]
    pub fn min_operations(s: String) -> i32 {
        let mut cnt_0 = 0;
        let mut cnt_1 = 0;
        for (i, ch) in s.chars().enumerate() {
            if (i % 2) as u8 == b'1' - ch as u8 {
                cnt_0 += 1;
            } else {
                cnt_1 += 1;
            }
        }
        cnt_0.min(cnt_1)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
