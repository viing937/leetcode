impl Solution {
    #[allow(unused)]
    pub fn truncate_sentence(s: String, k: i32) -> String {
        s.split(' ').take(k as usize).collect::<Vec<_>>().join(" ")
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
