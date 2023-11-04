impl Solution {
    #[allow(dead_code)]
    pub fn get_last_moment(n: i32, left: Vec<i32>, right: Vec<i32>) -> i32 {
        let mut rslt = 0;
        for t in left {
            rslt = rslt.max(t);
        }
        for t in right {
            rslt = rslt.max(n - t);
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
