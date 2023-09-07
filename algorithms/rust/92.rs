#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

impl Solution {
    #[allow(dead_code)]
    pub fn reverse_between(
        head: Option<Box<ListNode>>,
        left: i32,
        right: i32,
    ) -> Option<Box<ListNode>> {
        let (left, right) = (left as usize, right as usize);
        let mut dummy = Box::new(ListNode { val: 0, next: head });

        let mut tail = &mut dummy;
        for _ in 1..left {
            tail = tail.next.as_mut()?;
        }

        let remaining = tail.next.take();
        let (mut rev_list, mut remaining) = Self::take(remaining, right - left + 1);

        while let Some(mut node) = rev_list {
            rev_list = node.next.take();
            node.next = remaining;
            remaining = Some(node);
        }
        tail.next = remaining;

        dummy.next
    }

    fn take(
        mut head: Option<Box<ListNode>>,
        n: usize,
    ) -> (Option<Box<ListNode>>, Option<Box<ListNode>>) {
        let mut dummy = Box::new(ListNode::new(0));
        let mut tail = &mut dummy;
        for _ in 0..n {
            tail.next = head;
            tail = tail.next.as_mut().unwrap();
            head = tail.next.take();
        }
        (dummy.next, head)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
