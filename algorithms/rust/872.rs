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
    pub fn leaf_similar(
        root_1: Option<Rc<RefCell<TreeNode>>>,
        root_2: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        let leaf_value_list_1 = Self::leaf_value_list(root_1);
        let leaf_value_list_2 = Self::leaf_value_list(root_2);
        if leaf_value_list_1.len() != leaf_value_list_2.len() {
            return false;
        }
        for (value_1, value_2) in leaf_value_list_1.iter().zip(leaf_value_list_2.iter()) {
            if value_1 != value_2 {
                return false;
            }
        }
        true
    }

    fn leaf_value_list(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut rslt = vec![];
        if let Some(node) = root {
            let node = node.borrow();
            if node.left.is_none() && node.right.is_none() {
                rslt.push(node.val);
            } else {
                let left_value_list = Self::leaf_value_list(node.left.clone());
                let right_value_list = Self::leaf_value_list(node.right.clone());
                rslt.extend(left_value_list);
                rslt.extend(right_value_list);
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
