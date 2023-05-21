use std::collections::HashMap;

impl Solution {
    pub fn max_equal_rows_after_flips(nums: Vec<Vec<i32>>) -> i32 {
        let (n, m) = (nums.len(), nums[0].len());
        let mut map = HashMap::new();
        for i in 0..n {
            let mut s = String::with_capacity(m);
            for j in 0..m {
                s.push(char::from_digit(nums[i][j] as u32 & nums[i][0] as u32, 10).unwrap());
            }
            *map.entry(s).or_insert(0) += 1;
        }
        *map.values().into_iter().max().unwrap()
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use std::env;
    use super::*;

    #[test]
    fn test1072() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::max_equal_rows_after_flips(vec![vec![0,1],vec![1,1]]), 1);
        assert_eq!(Solution::max_equal_rows_after_flips(vec![vec![0,1],vec![1,0]]), 2);
    }

}
