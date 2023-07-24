impl Solution {
    #[allow(unused)]
    pub fn length_of_last_word(s: String) -> i32 {
        s.split(' ')
            .filter(|word| !word.is_empty())
            .next_back()
            .unwrap()
            .len() as i32
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
