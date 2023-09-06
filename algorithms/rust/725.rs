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
    pub fn split_list_to_parts(
        mut head: Option<Box<ListNode>>,
        k: i32,
    ) -> Vec<Option<Box<ListNode>>> {
        let k = k as usize;
        let mut cnt = 0;
        let mut cur = &head;
        while let Some(node) = cur {
            cur = &node.next;
            cnt += 1;
        }

        let mut rslt = vec![];
        let mut part;

        for i in 0..k {
            let n = cnt / k + if i < cnt % k { 1 } else { 0 };
            let split = Self::take(head, n);
            part = split.0;
            head = split.1;
            rslt.push(part);
        }

        rslt
    }

    fn take(
        mut head: Option<Box<ListNode>>,
        mut n: usize,
    ) -> (Option<Box<ListNode>>, Option<Box<ListNode>>) {
        if head.is_none() {
            return (None, head);
        }

        let mut part = Box::new(ListNode::new(0));
        let mut tail = &mut part;
        while let Some(node) = head {
            tail.next = Some(node);
            tail = tail.next.as_mut().unwrap();
            head = tail.next.take();
            n -= 1;
            if n == 0 {
                break;
            }
        }
        (part.next, head)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
