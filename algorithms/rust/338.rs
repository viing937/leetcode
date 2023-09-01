impl Solution {
    #[allow(dead_code)]
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut rslt = vec![];

        for mut i in 0..=n {
            let mut cnt = 0;
            while i > 0 {
                cnt += i % 2;
                i /= 2;
            }
            rslt.push(cnt);
        }

        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
