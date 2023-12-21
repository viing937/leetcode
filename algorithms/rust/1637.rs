impl Solution {
    #[allow(dead_code)]
    pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
        let mut vec_x: Vec<i32> = points.iter().map(|p| p[0]).collect();
        vec_x.sort();

        let mut rslt = 0;
        for i in 1..vec_x.len() {
            rslt = rslt.max(vec_x[i] - vec_x[i - 1]);
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
