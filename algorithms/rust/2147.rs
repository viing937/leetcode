impl Solution {
    #[allow(dead_code)]
    pub fn number_of_ways(corridor: String) -> i32 {
        let mod_ = 1_000_000_000 + 7;
        let corridor: Vec<u8> = corridor.into_bytes();

        let num_s: usize = corridor
            .iter()
            .map(|&ch| if ch == b'S' { 1 } else { 0 })
            .sum();
        if num_s % 2 != 0 || num_s == 0 {
            return 0;
        }

        let mut rslt: usize = 1;
        let mut p_cnt = 0;
        let mut s_cnt = 0;
        let mut start = true;
        for ch in corridor {
            if ch == b'P' && s_cnt == 0 {
                p_cnt += 1;
            } else if ch == b'S' {
                s_cnt += 1;
            }
            if s_cnt == 2 {
                if !start {
                    rslt = (rslt * (p_cnt + 1)) % mod_;
                }
                s_cnt = 0;
                p_cnt = 0;
                start = false;
            }
        }

        rslt as i32
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
