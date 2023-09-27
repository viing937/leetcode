impl Solution {
    #[allow(dead_code)]
    pub fn decode_at_index(s: String, k: i32) -> String {
        let mut k = k as u64 - 1;
        let s: Vec<char> = s.chars().collect();
        let mut len_arr = vec![];
        for ch in s.iter() {
            let cur = if ch.is_alphabetic() {
                len_arr.last().unwrap_or(&0) + 1
            } else {
                len_arr.last().unwrap_or(&0) * ch.to_digit(10).unwrap() as u64
            };
            len_arr.push(cur);
            if cur > k {
                break;
            }
        }
        while !len_arr.is_empty() {
            let idx = len_arr.len() - 1;
            if s[idx].is_alphabetic() {
                if k + 1 == len_arr[idx] {
                    return s[idx].to_string();
                }
            } else {
                k %= len_arr[idx - 1];
            }
            len_arr.pop();
        }
        "".to_owned()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
