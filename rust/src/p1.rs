use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::with_capacity(nums.len());
        for (i, n) in nums.iter().enumerate() {
            match map.get(&(target - n)) {
                None => {
                    map.insert(n, i);
                }
                Some(ii) => return vec![*ii as i32, i as i32],
            }
        }
        vec![]
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::Solution;

    #[test]
    fn test() {
        assert_eq!(Solution::two_sum(vec![2, 7, 11, 5], 9), vec![0, 1]);
    }
}
