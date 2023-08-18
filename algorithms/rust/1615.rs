impl Solution {
    #[allow(dead_code)]
    pub fn maximal_network_rank(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut g = vec![vec![0; n]; n];
        let mut cnt = vec![0; n];

        for road in roads {
            let (ai, bi) = (road[0] as usize, road[1] as usize);
            g[ai][bi] += 1;
            g[bi][ai] += 1;
            cnt[ai] += 1;
            cnt[bi] += 1;
        }

        let mut rslt = 0;
        for i in 0..n {
            for j in 0..n {
                if i == j {
                    continue;
                }
                rslt = rslt.max(cnt[i] + cnt[j] - g[i][j]);
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
