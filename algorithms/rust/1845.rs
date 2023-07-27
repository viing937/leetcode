use std::{cmp::Reverse, collections::BinaryHeap};

struct SeatManager {
    seats: BinaryHeap<Reverse<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SeatManager {
    #[allow(unused)]
    fn new(n: i32) -> Self {
        Self {
            seats: BinaryHeap::from((0..n).map(|x| Reverse(x + 1)).collect::<Vec<_>>()),
        }
    }

    #[allow(unused)]
    fn reserve(&mut self) -> i32 {
        self.seats.pop().unwrap().0
    }

    #[allow(unused)]
    fn unreserve(&mut self, seat_number: i32) {
        self.seats.push(Reverse(seat_number));
    }
}

fn main() {
    println!("Hello, world!");
}
