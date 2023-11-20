impl Solution {
    #[allow(dead_code)]
    pub fn garbage_collection(garbage: Vec<String>, travel: Vec<i32>) -> i32 {
        let mut coullect_time = garbage[0].len() as i32;
        let mut travel_sum = 0;
        let (mut travel_m, mut travel_p, mut travel_g) = (0, 0, 0);
        for (house, dist) in garbage.iter().skip(1).zip(travel.iter()) {
            coullect_time += house.len() as i32;
            travel_sum += dist;
            if house.contains('M') {
                travel_m = travel_sum;
            }
            if house.contains('G') {
                travel_g = travel_sum;
            }
            if house.contains('P') {
                travel_p = travel_sum;
            }
        }
        coullect_time + travel_m + travel_g + travel_p
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
