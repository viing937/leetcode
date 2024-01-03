impl Solution {
    #[allow(dead_code)]
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut last_cnt = 0;
        let mut rslt = 0;
        for row in bank {
            let cnt = row.bytes().filter(|x| *x == b'1').count();
            if cnt != 0 {
                rslt += last_cnt * cnt;
                last_cnt = cnt;
            }
        }
        rslt as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
