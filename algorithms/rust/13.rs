use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn roman_to_int(s: String) -> i32 {
        let symbol = HashMap::from([
            (b'I', 1),
            (b'V', 5),
            (b'X', 10),
            (b'L', 50),
            (b'C', 100),
            (b'D', 500),
            (b'M', 1000),
        ]);

        let mut result = 0;

        let s = s.as_bytes();
        for i in 0..s.len() {
            if let Some(num) = symbol.get(&s[i]) {
                let mut sign = 1;
                if i + 1 < s.len()
                    && (s[i] == b'I' && (s[i + 1] == b'V' || s[i + 1] == b'X')
                        || s[i] == b'X' && (s[i + 1] == b'L' || s[i + 1] == b'C')
                        || s[i] == b'C' && (s[i + 1] == b'D' || s[i + 1] == b'M'))
                {
                    sign = -1;
                }
                result += sign * num;
            }
        }

        result
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
