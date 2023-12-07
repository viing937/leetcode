impl Solution {
    #[allow(dead_code)]
    pub fn largest_odd_number(num: String) -> String {
        let mut start = false;
        let mut rslt = String::new();
        for ch in num.chars().rev() {
            if ch == '1' || ch == '3' || ch == '5' || ch == '7' || ch == '9' {
                start = true;
            }
            if start {
                rslt.push(ch);
            }
        }
        rslt.chars().rev().collect()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
