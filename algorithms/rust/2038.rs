impl Solution {
    #[allow(dead_code)]
    pub fn winner_of_game(colors: String) -> bool {
        let (mut cnt_a, mut cnt_b) = (0, 0);
        let mut op = 0;
        for ch in colors.chars() {
            if ch == 'A' {
                cnt_a += 1;
                cnt_b = 0;
                if cnt_a >= 3 {
                    op += 1;
                }
            } else if ch == 'B' {
                cnt_a = 0;
                cnt_b += 1;
                if cnt_b >= 3 {
                    op -= 1;
                }
            }
        }
        op > 0
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
