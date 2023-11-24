impl Solution {
    #[allow(dead_code)]
    pub fn max_coins(mut piles: Vec<i32>) -> i32 {
        piles.sort();
        let mut rslt = 0;
        let mut iter = piles.iter().rev();
        for _ in 0..(piles.len() / 3) {
            iter.next();
            rslt += iter.next().unwrap();
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
