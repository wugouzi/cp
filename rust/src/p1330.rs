use std::cmp;

impl Solution {
    pub fn max_value_after_reverse(nums: Vec<i32>) -> i32 {
        let mut base = 0;
        let n = nums.len();
        for i in 0..n-1 {
            base += i32::abs(nums[i] - nums[i + 1]);
        }
        let mut ans = base;
        println!("{ans}");
        // case 1 l = 0
        for i in 1..n - 1 {
            ans = cmp::max(ans, base - i32::abs(nums[i] - nums[i + 1]) + i32::abs(nums[0] - nums[i + 1]));
            let j = n - i - 1;
            ans = cmp::max(ans, base - i32::abs(nums[j] - nums[j - 1]) + i32::abs(nums[n-1] - nums[j-1]));
        }
        let (mut m1, mut m2) = (i32::MIN, i32::MAX);
        for i in 0..n-1 {
            m1 = cmp::max(m1, cmp::min(nums[i], nums[i+1]));
            m2 = cmp::min(m2, cmp::max(nums[i], nums[i+1]));
        }
        cmp::max(ans, base + 2 * (m1 - m2))
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use std::env;
    use super::*;

    #[test]
    fn test1330() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::max_value_after_reverse(vec![2,3,1,5,4]), 10);
        assert_eq!(Solution::max_value_after_reverse(vec![2,4,9,24,2,1,10]), 68);
        assert_eq!(Solution::max_value_after_reverse(vec![2,5,1,3,4]), 11);
    }

}
