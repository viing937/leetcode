impl Solution {
    #[allow(dead_code)]
    pub fn get_winner(arr: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        if k == 1 {
            return arr[0].max(arr[1]);
        }
        if k >= arr.len() {
            return *arr.iter().max().unwrap();
        }

        let mut current_winner = arr[0];
        let mut consecutive_wins = 0;

        for &num in arr.iter().skip(1) {
            if num > current_winner {
                current_winner = num;
                consecutive_wins = 0;
            } else {
                consecutive_wins += 1;
            }

            if consecutive_wins == k {
                return current_winner;
            }
        }
        current_winner
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
