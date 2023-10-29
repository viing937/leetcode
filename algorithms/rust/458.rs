impl Solution {
    #[allow(dead_code)]
    pub fn poor_pigs(buckets: i32, minutes_to_die: i32, minutes_to_test: i32) -> i32 {
        let base = (minutes_to_test / minutes_to_die) + 1;
        let mut x = 0;
        let mut p = 1;
        while p < buckets {
            p *= base;
            x += 1;
        }
        x
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
