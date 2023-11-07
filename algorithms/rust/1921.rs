impl Solution {
    #[allow(dead_code)]
    pub fn eliminate_maximum(dist: Vec<i32>, speed: Vec<i32>) -> i32 {
        let mut time: Vec<i32> = dist
            .iter()
            .zip(speed.iter())
            .map(|(d, s)| (d + s - 1) / s)
            .collect();
        time.sort();
        let mut rslt = 0;
        for m in time {
            if rslt >= m {
                break;
            } else {
                rslt += 1;
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
