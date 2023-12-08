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
    pub fn tree2str(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        if let Some(root) = root {
            let left = Self::tree2str(root.borrow().left.clone());
            let right = Self::tree2str(root.borrow().right.clone());
            if !right.is_empty() {
                format!("{}({})({})", root.borrow().val, left, right)
            } else if !left.is_empty() {
                format!("{}({})", root.borrow().val, left)
            } else {
                format!("{}", root.borrow().val)
            }
        } else {
            "".to_string()
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
