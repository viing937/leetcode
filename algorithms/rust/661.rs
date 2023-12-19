impl Solution {
    #[allow(dead_code)]
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (img.len(), img[0].len());
        let mut rslt = vec![vec![0; n]; m];
        for (i, v) in img.iter().enumerate() {
            for (j, _) in v.iter().enumerate() {
                let (mut sum, mut cnt) = (0, 0);
                for row in img
                    .iter()
                    .take(if i + 1 == m { i } else { i + 1 } + 1)
                    .skip(i.saturating_sub(1))
                {
                    for val in row
                        .iter()
                        .take(if j + 1 == n { j } else { j + 1 } + 1)
                        .skip(j.saturating_sub(1))
                    {
                        sum += val;
                        cnt += 1;
                    }
                }
                rslt[i][j] = sum / cnt;
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
