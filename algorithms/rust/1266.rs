impl Solution {
    #[allow(dead_code)]
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut rslt = 0;
        for i in 1..n {
            let (cur, prev) = (&points[i], &points[i - 1]);
            let diff_x = (cur[0] - prev[0]).abs();
            let diff_y = (cur[1] - prev[1]).abs();
            rslt += diff_x.max(diff_y);
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
