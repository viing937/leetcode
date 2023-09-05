impl Solution {
    #[allow(dead_code)]
    pub fn is_valid(s: String) -> bool {
        let mut stack = vec![];
        for ch in s.chars() {
            if ch == '(' || ch == '{' || ch == '[' {
                stack.push(ch);
            } else {
                match stack.pop() {
                    Some(left) => {
                        if left == '(' && ch != ')'
                            || left == '{' && ch != '}'
                            || left == '[' && ch != ']'
                        {
                            return false;
                        }
                    }
                    None => return false,
                }
            }
        }
        stack.is_empty()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
