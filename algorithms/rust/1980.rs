impl Solution {
    #[allow(dead_code)]
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let mut bytes: Vec<u8> = nums[0].bytes().collect();
        let mut idx = 0;

        while let Ok(s) = String::from_utf8(bytes.to_vec()) {
            if !nums.contains(&s) {
                return s;
            }
            bytes[idx] = Self::inverse(bytes[idx]);
            idx += 1;
        }
        nums[0].clone()
    }

    fn inverse(ch: u8) -> u8 {
        if ch == b'0' {
            b'1'
        } else {
            b'0'
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
