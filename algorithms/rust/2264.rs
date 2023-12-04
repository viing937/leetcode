impl Solution {
    #[allow(dead_code)]
    pub fn largest_good_integer(num: String) -> String {
        let mut rslt = -1;
        let num = num.as_bytes();
        for i in 2..num.len() {
            if num[i - 2] == num[i - 1] && num[i] == num[i - 1] {
                let tmp: i32 = String::from_utf8(num[i - 2..i + 1].to_vec())
                    .unwrap()
                    .parse()
                    .unwrap();
                rslt = rslt.max(tmp);
            }
        }
        if rslt == -1 {
            "".to_owned()
        } else {
            format!("{:03}", rslt)
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
