use std::cell::RefCell;
use std::rc::Rc;

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
    #[allow(unused)]
    pub fn generate_trees(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        Self::build(1, n)
    }

    fn build(left: i32, right: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        if left > right {
            return vec![None];
        }
        let mut rslt = vec![];
        for mid in left..=right {
            for left_tree in Self::build(left, mid - 1) {
                for right_tree in Self::build(mid + 1, right) {
                    let mut root = TreeNode::new(mid);
                    root.left = left_tree.to_owned();
                    root.right = right_tree.to_owned();
                    rslt.push(Some(Rc::new(RefCell::new(root))));
                }
            }
        }
        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
