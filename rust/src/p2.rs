use crate::util::linked_list::{ListNode};

impl Solution {
  pub fn add_two_numbers(
    l1: Option<Box<ListNode>>,
    l2: Option<Box<ListNode>>
  ) -> Option<Box<ListNode>> {
    Self::carried(l1, l2, 0)
  }
  pub fn carried(
    l1: Option<Box<ListNode>>,
    l2: Option<Box<ListNode>>,
    mut carry: i32
  ) -> Option<Box<ListNode>> {
    if l1.is_none() && l2.is_none() && carry == 0 {
      None
    } else {
      Some(Box::new(ListNode{
        next: Self::carried(
          l1.and_then(|x| {carry += x.val; x.next}),
          l2.and_then(|x| {carry += x.val; x.next}),
          carry / 10
        ),
        val: carry % 10
      }))
    }

  }
  pub fn add_two_numbers1(
    l1: Option<Box<ListNode>>,
    l2: Option<Box<ListNode>>
  ) -> Option<Box<ListNode>> {
        // some implementation
      let (mut l1, mut l2) = (l1, l2);
      let mut ans = Some(Box::new(ListNode::new(-1)));
      let mut tail = &mut ans;
      let mut add = 0;
      let (mut l1_end, mut l2_end) = (false, false);
      loop {
        let lhs = match l1 {
          Some(node) => {
            l1 = node.next;
            node.val
          }
          None => {
            l1_end = true;
            0
          }
        };
        let rhs = match l2 {
          Some(node) => {
            l2 = node.next;
            node.val
          }
          None => {
            l2_end = true;
            0
          }
        };
        if l1_end && l2_end && add == 0 {
          break;
        }
        let sum = lhs + rhs + add;
        add = sum / 10;
        let sum = sum % 10;
        tail.as_mut().unwrap().next = Some(Box::new(ListNode::new(sum)));
        tail = &mut tail.as_mut().unwrap().next;
      }
      ans.unwrap().next
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
  extern crate test;
  use super::*;
  use crate::util::linked_list::to_list;

  #[test]
  fn test2() {
    assert_eq!(
      Solution::add_two_numbers(to_list(vec![2, 4, 3]), to_list(vec![5, 6, 4])),
      to_list(vec![7, 0, 8])
    );

    assert_eq!(
      Solution::add_two_numbers(to_list(vec![9, 9, 9, 9]), to_list(vec![9, 9, 9, 9, 9, 9])),
      to_list(vec![8, 9, 9, 9, 0, 0, 1])
    );

    assert_eq!(
      Solution::add_two_numbers(to_list(vec![0]), to_list(vec![0])),
      to_list(vec![0])
    )
  }

}
