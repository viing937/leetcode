impl Solution {
    #[allow(dead_code)]
    pub fn maximum_element_after_decrementing_and_rearranging(mut arr: Vec<i32>) -> i32 {
        arr.sort();
        arr[0] = 1;
        for i in 1..arr.len() {
            if arr[i] - arr[i - 1] > 1 {
                arr[i] = arr[i - 1] + 1;
            }
        }
        *arr.last().unwrap()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
