impl Solution {
    #[allow(dead_code)]
    pub fn longest_str_chain(mut words: Vec<String>) -> i32 {
        words.sort_by_key(|x| x.len());

        let n = words.len();
        let mut dp = vec![1; n + 1];
        let mut rslt = 1;

        let mut j = 0;
        for (i, w1) in words.iter().enumerate() {
            while j < n {
                if words[j].len() <= w1.len() {
                    j += 1;
                } else {
                    for (k, w2) in words.iter().enumerate().skip(j) {
                        if w1.len() + 1 != w2.len() {
                            break;
                        }
                        if Self::is_predecessor(w1, w2) {
                            dp[k + 1] = dp[k + 1].max(dp[i + 1] + 1);
                        }
                        rslt = rslt.max(dp[k + 1]);
                    }
                    break;
                }
            }
        }

        rslt
    }

    pub fn is_predecessor(a: &str, b: &str) -> bool {
        if a.len() + 1 != b.len() {
            return false;
        }
        let mut cnt = 0;
        let mut b_iter = b.chars();
        for ch_a in a.chars() {
            for ch_b in b_iter.by_ref() {
                if ch_a == ch_b {
                    break;
                } else {
                    cnt += 1;
                }
            }
        }
        let rslt = cnt + b_iter.count();
        rslt == 1
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
