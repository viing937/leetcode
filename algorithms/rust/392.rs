impl Solution {
    #[allow(unused)]
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut t = t.chars();
        for c in s.chars() {
            loop {
                match t.next() {
                    Some(ch) => {
                        if c == ch {
                            break;
                        }
                    }
                    _ => return false,
                }
            }
        }
        true
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
