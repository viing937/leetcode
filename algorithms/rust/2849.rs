impl Solution {
    #[allow(dead_code)]
    pub fn is_reachable_at_time(sx: i32, sy: i32, fx: i32, fy: i32, t: i32) -> bool {
        let dis_x = (sx - fx).abs();
        let dis_y = (sy - fy).abs();
        let dis_t = (dis_x - dis_y).abs() + dis_x.min(dis_y);
        if dis_t == 0 && t == 1 {
            return false;
        }
        dis_t <= t
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
