impl Solution {
    #[allow(dead_code)]
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let mut rslt = vec![];
        let mut cur = 1;
        for item in target {
            while cur < item {
                rslt.push("Push".to_string());
                rslt.push("Pop".to_string());
                cur += 1;
            }
            rslt.push("Push".to_string());
            cur += 1;
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
