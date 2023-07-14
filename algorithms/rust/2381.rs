impl Solution {
    #[allow(unused)]
    pub fn shifting_letters(s: String, shifts: Vec<Vec<i32>>) -> String {
        let n = s.len();
        let mut diffs = vec![0; n + 1];
        for shift in shifts.into_iter() {
            let (start, end, dir) = (shift[0], shift[1], shift[2]);
            if dir == 1 {
                diffs[start as usize] += 1;
                diffs[end as usize + 1] -= 1;
            } else {
                diffs[start as usize] -= 1;
                diffs[end as usize + 1] += 1;
            }
        }
        for i in 1..n + 1 {
            diffs[i] = diffs[i - 1] + diffs[i];
        }
        return s
            .chars()
            .zip(diffs)
            .map(|(c, diff)| Self::char_operator(c, diff))
            .collect();
    }

    fn char_operator(c: char, offset: i32) -> char {
        let base = c as u8 - b'a';
        let base = (base + (offset % 26 + 26) as u8) % 26;
        return (base + b'a') as char;
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
