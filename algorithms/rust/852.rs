impl Solution {
    #[allow(unused)]
    pub fn peak_index_in_mountain_array(arr: Vec<i32>) -> i32 {
        let (mut left, mut right) = (0, arr.len() - 1);
        while (left < right) {
            let mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid as i32;
            } else if (arr[mid] <= arr[mid + 1]) {
                left = mid;
            } else if (arr[mid] <= arr[mid - 1]) {
                right = mid;
            }
        }
        left as i32
    }
}

#[allow(dead_code)]
struct Solution;

fn main() {
    println!("Hello, world!");
}
