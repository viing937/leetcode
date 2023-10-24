use std::cell::RefCell;
use std::rc::Rc;

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

impl Solution {
    #[allow(dead_code)]
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result = vec![];
        Self::dfs(root, 0, &mut result);
        result
    }

    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, depth: usize, max_value: &mut Vec<i32>) {
        if let Some(node) = root {
            let node = node.borrow();
            let value = node.val;
            if depth < max_value.len() {
                max_value[depth] = max_value[depth].max(value);
            } else {
                max_value.push(value);
            }
            Self::dfs(node.left.clone(), depth + 1, max_value);
            Self::dfs(node.right.clone(), depth + 1, max_value);
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
