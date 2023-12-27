impl Solution {
    #[allow(dead_code)]
    pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
        let mut rslt = 0;
        let colors: Vec<char> = colors.chars().collect();
        let mut prev = 0;
        for (i, &ch) in colors.iter().enumerate().skip(1) {
            if ch == colors[prev] {
                if needed_time[i] < needed_time[prev] {
                    rslt += needed_time[i];
                } else {
                    rslt += needed_time[prev];
                    prev = i;
                }
            } else {
                prev = i;
            }
            println!("{:?} {:?} {:?}", prev, i, rslt);
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
