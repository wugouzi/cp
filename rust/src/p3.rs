use std::collections::HashSet;
use std::cmp;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let seq: Vec<char> = s.chars().collect();
        let len = seq.len();
        let (mut l, mut r, mut ans) = (0, 0, 0);
        let mut set = HashSet::new();
        while r < len {
            if set.contains(&seq[r]) {
                while seq[l] != seq[r] {
                    set.remove(&seq[l]);
                    l += 1;
                }
                l += 1;
            }
            set.insert(seq[r]);
            ans = cmp::max(ans, r - l + 1);
            r += 1;
        }
        ans as i32
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::*;

    #[test]
    fn test3() {
        assert_eq!(Solution::length_of_longest_substring(String::from("abcabcbb")), 3);
    }

}
