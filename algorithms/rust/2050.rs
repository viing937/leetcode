use std::collections::HashSet;

impl Solution {
    #[allow(dead_code)]
    pub fn minimum_time(n: i32, relations: Vec<Vec<i32>>, time: Vec<i32>) -> i32 {
        let n = n as usize;
        let mut dep = vec![HashSet::new(); n];
        for r in relations {
            dep[r[1] as usize - 1].insert(r[0] as usize - 1);
        }

        let mut dp = vec![0; n];
        let mut rslt = 0;
        for i in 0..n {
            rslt = rslt.max(Self::dfs(i, &mut dp, &time, &dep));
        }
        rslt
    }

    fn dfs(i: usize, dp: &mut Vec<i32>, time: &Vec<i32>, dep: &Vec<HashSet<usize>>) -> i32 {
        if dp[i] != 0 {
            return dp[i];
        }
        let mut prev = 0;
        for &d in dep.get(i).unwrap_or(&HashSet::new()).iter() {
            prev = prev.max(Self::dfs(d, dp, time, dep));
        }
        dp[i] = time[i] + prev;
        dp[i]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
