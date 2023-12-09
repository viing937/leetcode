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
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        if let Some(root) = root {
            let root = root.borrow();
            let mut rslt = Self::inorder_traversal(root.left.clone());
            rslt.push(root.val);
            rslt.extend(Self::inorder_traversal(root.right.clone()));
            rslt
        } else {
            vec![]
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
