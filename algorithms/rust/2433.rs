impl Solution {
    #[allow(dead_code)]
    pub fn find_array(pref: Vec<i32>) -> Vec<i32> {
        let mut rslt = vec![];
        let mut base = 0;
        for p in pref {
            rslt.push(p ^ base);
            base = p;
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
