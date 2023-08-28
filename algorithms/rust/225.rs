use std::collections::VecDeque;

struct MyStack {
    swap: VecDeque<i32>,
    queue: VecDeque<i32>,
    top: i32,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
#[allow(dead_code)]
impl MyStack {
    fn new() -> Self {
        Self {
            swap: VecDeque::new(),
            queue: VecDeque::new(),
            top: 0,
        }
    }

    fn push(&mut self, x: i32) {
        self.top = x;
        self.queue.push_back(x);
    }

    fn pop(&mut self) -> i32 {
        let result = self.top;
        while let Some(value) = self.queue.pop_front() {
            if !self.queue.is_empty() {
                self.swap.push_back(value);
                self.top = value;
            }
        }
        std::mem::swap(&mut self.queue, &mut self.swap);
        result
    }

    fn top(&self) -> i32 {
        self.top
    }

    fn empty(&self) -> bool {
        self.queue.is_empty() && self.swap.is_empty()
    }
}

fn main() {
    println!("Hello, world!");
}
