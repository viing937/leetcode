impl Solution {
    #[allow(dead_code)]
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let mut arr_with_bits = vec![];
        for num in arr {
            let mut bits = 0;
            let mut tmp = num;
            while tmp > 0 {
                bits += tmp & 1;
                tmp >>= 1;
            }
            arr_with_bits.push((bits, num));
        }
        arr_with_bits.sort();
        arr_with_bits.iter().map(|(_, num)| *num).collect()
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
