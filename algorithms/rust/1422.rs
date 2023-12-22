impl Solution {
    #[allow(dead_code)]
    pub fn max_score(s: String) -> i32 {
        let mut cnt_left_0: i32 = 0;
        let mut cnt_right_1: i32 = s.chars().map(|ch| if ch == '1' { 1 } else { 0 }).sum();

        let mut rslt = 0;
        for ch in s.chars().take(s.len() - 1) {
            cnt_left_0 += if ch == '0' { 1 } else { 0 };
            cnt_right_1 -= if ch == '1' { 1 } else { 0 };
            rslt = rslt.max(cnt_left_0 + cnt_right_1);
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
