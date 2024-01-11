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
use std::rc::Rc;

impl Solution {
    #[allow(dead_code)]
    pub fn max_ancestor_diff(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut rslt = 0;
        if let Some(root) = &root {
            Self::solve(root, &mut rslt);
        }
        rslt
    }

    fn solve(root: &Rc<RefCell<TreeNode>>, max_diff: &mut i32) -> (i32, i32) {
        let root = root.borrow();
        let (mut min_v, mut max_v) = (i32::MAX, i32::MIN);
        if let Some(child) = &root.left {
            let (min_t, max_t) = Self::solve(child, max_diff);
            min_v = min_v.min(min_t);
            max_v = max_v.max(max_t);
        }
        if let Some(child) = &root.right {
            let (min_t, max_t) = Self::solve(child, max_diff);
            min_v = min_v.min(min_t);
            max_v = max_v.max(max_t);
        }
        if min_v != i32::MAX {
            *max_diff = *max_diff.max(&mut (root.val - min_v).abs());
        }
        if max_v != i32::MIN {
            *max_diff = *max_diff.max(&mut (root.val - max_v).abs());
        }
        min_v = min_v.min(root.val);
        max_v = max_v.max(root.val);
        (min_v, max_v)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
