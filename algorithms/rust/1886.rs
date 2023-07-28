impl Solution {
    #[allow(unused)]
    pub fn find_rotation(mat: Vec<Vec<i32>>, target: Vec<Vec<i32>>) -> bool {
        let mut mat = mat;
        for _ in 0..4 {
            if mat == target {
                return true;
            }
            Self::rotate(&mut mat);
        }
        false
    }

    fn rotate(mat: &mut Vec<Vec<i32>>) {
        for i in 0..mat.len() {
            for j in 0..i {
                let t = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = t;
            }
        }
        mat.iter_mut().for_each(|row| row.reverse());
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
