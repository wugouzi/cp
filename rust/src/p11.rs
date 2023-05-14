use std::cmp;
impl Solution {
    pub fn max_area(h: Vec<i32>) -> i32 {
        let (mut l, mut r) = (0, h.len() - 1);
        let mut ans = 0;
        while l < r {
            ans = cmp::max(ans, (r - l) as i32 * cmp::min(h[l], h[r]));
            if h[l] < h[r] {
                l += 1;
            } else {
                r -= 1;
            }
        }
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
    fn test11() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::max_area(vec![1,8,6,2,5,4,8,3,7]), 49);

    }

}
