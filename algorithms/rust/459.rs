impl Solution {
    #[allow(dead_code)]
    pub fn repeated_substring_pattern(s: String) -> bool {
        let n = s.len();

        let s_bytes = s.as_bytes();
        for i in 1..=(n / 2) {
            if n % i != 0 {
                continue;
            }
            let mut flag = true;
            for (idx, &ch) in s_bytes.iter().enumerate() {
                if ch != s_bytes[idx % i] {
                    flag = false;
                    break;
                }
            }
            if flag {
                return true;
            }
        }
        false
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
