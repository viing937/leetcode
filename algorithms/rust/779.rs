impl Solution {
    #[allow(dead_code)]
    pub fn kth_grammar(n: i32, k: i32) -> i32 {
        let mut paths = vec![k];
        for _ in 1..n {
            let last = paths.last().unwrap();
            paths.push((last + 1) / 2);
        }
        let mut rslt = 0;
        for path in paths.iter().rev() {
            if path % 2 == 0 {
                rslt = 1 - rslt;
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
