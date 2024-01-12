impl Solution {
    #[allow(dead_code)]
    pub fn halves_are_alike(s: String) -> bool {
        let mut char_cnt = 0;
        let half_cnt = s.len() / 2;
        for (i, ch) in s.chars().enumerate() {
            if !"aeiouAEIOU".contains(ch) {
                continue;
            }
            if i < half_cnt {
                char_cnt += 1;
            } else {
                char_cnt -= 1;
            }
        }
        char_cnt == 0
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
