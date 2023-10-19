impl Solution {
    #[allow(dead_code)]
    pub fn backspace_compare(s: String, t: String) -> bool {
        Self::input(s) == Self::input(t)
    }

    fn input(s: String) -> String {
        let mut new_s = String::new();
        for ch in s.chars() {
            if ch == '#' {
                new_s.pop();
            } else {
                new_s.push(ch);
            }
        }
        new_s
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
