impl Solution {
    #[allow(dead_code)]
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        g.sort();
        s.sort();
        let mut rslt = 0;
        let mut g_iter = g.iter().rev();
        for cookie in s.iter().rev() {
            for child in &mut g_iter {
                if cookie >= child {
                    rslt += 1;
                    break;
                }
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
