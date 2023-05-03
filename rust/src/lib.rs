#![allow(dead_code)]
#![feature(test)]
#![feature(proc_macro_hygiene)]
#![feature(box_patterns)]

pub use leetcode_prelude::{
    assert_eq_sorted, btree, leetcode_test, linkedlist, vec_string, ListNode, TreeNode,
};

pub mod p1;
pub mod p2;
pub mod p3;
pub mod util;
