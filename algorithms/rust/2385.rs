// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::collections::{HashMap, HashSet, VecDeque};
use std::rc::Rc;

impl Solution {
    #[allow(dead_code)]
    pub fn amount_of_time(root: Option<Rc<RefCell<TreeNode>>>, start: i32) -> i32 {
        let mut g = HashMap::new();
        Self::build_graph(&root, &mut g);

        let mut visited: HashSet<i32> = HashSet::new();
        visited.insert(start);
        let mut queue = VecDeque::new();
        queue.push_back((start, 0));

        let mut rslt = 0;
        while let Some((cur, step)) = queue.pop_front() {
            for next in g.get(&cur).unwrap_or(&vec![]).iter() {
                if !visited.contains(next) {
                    visited.insert(*next);
                    queue.push_back((*next, step + 1));
                }
            }
            rslt = step;
        }
        rslt
    }

    fn build_graph(root: &Option<Rc<RefCell<TreeNode>>>, g: &mut HashMap<i32, Vec<i32>>) {
        if let Some(node) = root {
            let node = node.borrow();
            if let Some(child) = &node.left {
                let child_val = child.borrow().val;
                g.entry(node.val).or_default().push(child_val);
                g.entry(child_val).or_default().push(node.val);
                Self::build_graph(&node.left, g);
            }
            if let Some(child) = &node.right {
                let child_val = child.borrow().val;
                g.entry(node.val).or_default().push(child_val);
                g.entry(child_val).or_default().push(node.val);
                Self::build_graph(&node.right, g);
            }
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
