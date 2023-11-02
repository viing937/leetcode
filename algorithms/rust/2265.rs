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
    pub fn average_of_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut rslt = 0;
        Self::dfs(&root, &mut rslt);
        rslt
    }

    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, rslt: &mut i32) -> (i32, i32) {
        if let Some(node) = root {
            let node = node.borrow();

            let (l_cnt, l_sum) = Self::dfs(&node.left, rslt);
            let (r_cnt, r_sum) = Self::dfs(&node.right, rslt);
            let (cnt, sum) = (l_cnt + r_cnt + 1, l_sum + r_sum + node.val);
            if sum / cnt == node.val {
                *rslt += 1;
            }
            return (cnt, sum);
        }
        (0, 0)
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
