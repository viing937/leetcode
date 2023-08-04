impl Solution {
    #[allow(unused)]
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let (mut lines, mut width) = (0, 0);
        for ch in s.chars() {
            let ch_width = widths[(ch as u8 - b'a') as usize];
            if width + ch_width > 100 {
                lines += 1;
                width = 0;
            }
            width += ch_width;
        }
        if width > 0 {
            lines += 1;
        }
        vec![lines, width]
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
