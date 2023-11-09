impl Solution {
    #[allow(dead_code)]
    pub fn count_homogenous(s: String) -> i32 {
        let mod_ = 1_000_000_007;
        let (mut last_ch, mut cnt) = (' ', 0);
        let mut rslt: i64 = 0;
        for ch in s.chars() {
            if ch == last_ch {
                cnt += 1;
            } else {
                rslt = (rslt + (1 + cnt) * cnt / 2 % mod_) % mod_;
                last_ch = ch;
                cnt = 1;
            }
        }
        rslt = (rslt + (1 + cnt) * cnt / 2 % mod_) % mod_;
        rslt as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
