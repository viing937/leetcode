use std::cell::RefCell;
use std::cmp::Ordering;
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
    pub fn find_mode(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut modes = vec![];
        let mut current_value = 0;
        let mut current_cnt = 0;
        let mut max_cnt = 0;
        Self::dfs(
            &root,
            &mut modes,
            &mut current_value,
            &mut current_cnt,
            &mut max_cnt,
        );
        modes
    }

    pub fn dfs(
        root: &Option<Rc<RefCell<TreeNode>>>,
        modes: &mut Vec<i32>,
        current_val: &mut i32,
        current_cnt: &mut i32,
        max_count: &mut i32,
    ) {
        if let Some(node) = root {
            let node = node.borrow();

            Self::dfs(&node.left, modes, current_val, current_cnt, max_count);

            if node.val == *current_val {
                *current_cnt += 1;
            } else {
                *current_cnt = 1;
            }
            *current_val = node.val;

            match current_cnt.cmp(&max_count) {
                Ordering::Equal => modes.push(node.val),
                Ordering::Greater => {
                    *max_count = *current_cnt;
                    *modes = vec![*current_val];
                }
                Ordering::Less => (),
            }

            Self::dfs(&node.right, modes, current_val, current_cnt, max_count);
        }
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
