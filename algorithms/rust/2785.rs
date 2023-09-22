impl Solution {
    #[allow(dead_code)]
    pub fn sort_vowels(s: String) -> String {
        let vowels = "aeiouAEIOU";

        let mut vowels_of_s = vec![];
        for ch in s.chars() {
            if vowels.contains(ch) {
                vowels_of_s.push(ch);
            }
        }

        vowels_of_s.sort();
        let mut vowels_of_s = vowels_of_s.into_iter();

        let mut rslt = String::new();
        for ch in s.chars() {
            if vowels.contains(ch) {
                rslt.push(vowels_of_s.next().unwrap());
            } else {
                rslt.push(ch);
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
