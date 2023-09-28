use std::{rc::Rc, cell::RefCell, collections::HashSet};

use leetcode_prelude::TreeNode;

impl Solution {
    fn help(root: &Option<Rc<RefCell<TreeNode>>>, to_delete: &HashSet<i32>,
            ans: &mut Vec<Option<Rc<RefCell<TreeNode>>>>) {
        if root.is_none() {
            return;
        }
        let root = root.as_ref().unwrap();


    }
    pub fn del_nodes(root: Option<Rc<RefCell<TreeNode>>>, to_delete: Vec<i32>)
                     -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        let new_root = Some(Rc::new(RefCell::new(TreeNode::new(-1))));
        new_root.as_ref().unwrap().borrow_mut().left = root;
        let mut ans : Vec<Option<Rc<RefCell<TreeNode>>>> = vec![];
        let mut set = HashSet::new();
        for v in &to_delete {
            set.insert(*v);
        }
        Self::help(&new_root, &set, &mut ans);
        ans
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use std::env;
    use super::*;

    #[test]
    fn test() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::function(), );
    }

}
