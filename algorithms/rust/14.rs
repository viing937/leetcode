impl Solution {
    #[allow(unused)]
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let n = strs.len();
        let mut solution = String::new();
        if n == 0 {
            return solution;
        }
        let mut strs = strs.clone();
        strs.sort();

        let first = strs.get(0).unwrap().chars();
        let mut last = strs.get(n - 1).unwrap().chars();

        for c in first {
            match last.next() {
                Some(ch) => {
                    if c == ch {
                        solution.push(c);
                    } else {
                        return solution;
                    }
                }
                _ => break,
            }
        }
        solution
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
