use std::{rc::Rc, cell::RefCell, cmp};
use leetcode_prelude::TreeNode;
impl Solution {
    fn help(root: &Option<Rc<RefCell<TreeNode>>>, ans: &mut i32) -> (bool, i32, i32, i32) {
        if root.is_none() {
            return (true, 0, i32::MIN, i32::MAX);
        }
        let root = root.as_ref().unwrap();
        let val = root.borrow().val;
        let l = Self::help(&root.borrow().left, ans);
        let r = Self::help(&root.borrow().right, ans);
        let hl = root.borrow().left.is_none();
        let hr = root.borrow().right.is_none();
        let mut res = false;
        if l.0 && r.0 {
            if hl || val > l.3 {
                if hr || val < r.2 {
                    res = true;
                    *ans = cmp::max(*ans, val + l.1 + r.1);
                }
            }
        }
        (res, val + l.1 + r.1,
         if hl { val } else { l.2},
         if hr { val } else { r.3})

    }
    pub fn max_sum_bst(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 0;
        Self::help(&root, &mut ans);
        ans
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use std::env;
    use leetcode_prelude::btree;

    use super::*;

    #[test]
    fn test1373() {
        env::set_var("RUST_BACKTRACE", "1");
        // assert_eq!(Solution::max_sum_bst(btree![1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]), 20);
        assert_eq!(Solution::max_sum_bst(btree![9,2,3,null,2,null,null,3,null,-5,4,null,1,null,10]), 14);
    }

}
