impl Solution {
    #[allow(dead_code)]
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut s: Vec<char> = s.chars().collect();
        let mut t: Vec<char> = t.chars().collect();

        s.sort();
        t.sort();

        for (a, b) in s.iter().zip(t.iter()) {
            if a != b {
                println!("{:?}, {:?}", a, b);
                return *b;
            }
        }
        *t.last().unwrap()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
