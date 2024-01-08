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
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        let mut rslt = 0;
        if let Some(node) = root {
            let node = node.borrow();
            if node.val >= low && node.val <= high {
                rslt += node.val;
            }
            if node.val > low {
                rslt += Self::range_sum_bst(node.left.clone(), low, high);
            }
            if node.val < high {
                rslt += Self::range_sum_bst(node.right.clone(), low, high);
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
