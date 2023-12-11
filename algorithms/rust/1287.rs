impl Solution {
    #[allow(dead_code)]
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let (mut last, mut cnt) = (arr[0], 1);
        for &num in arr.iter().skip(1) {
            if num == last {
                cnt += 1;
            } else {
                if cnt > n / 4 {
                    return last;
                }
                last = num;
                cnt = 1;
            }
        }
        last
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
