impl Solution {
    #[allow(dead_code)]
    pub fn convert_to_title(mut column_number: i32) -> String {
        let mut char_vec = vec![];
        while column_number > 0 {
            column_number -= 1;
            let ch = b'A' + (column_number % 26) as u8;
            column_number /= 26;
            char_vec.push(ch as char);
        }
        char_vec.iter().rev().collect()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
