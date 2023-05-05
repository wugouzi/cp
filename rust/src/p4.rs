use std::cmp;
impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (len1, len2) = (nums1.len() as i32, nums2.len() as i32);
        if len1 > len2 {
            return Self::find_median_sorted_arrays(nums2, nums1)
        }
        let (mut med1, mut med2) = (0, 0);
        let (mut l, mut r) = (0, len1);
        while l <= r {
            let i = (l + r) / 2;
            let j = (len1 + len2 + 1) / 2 - i;
            let l1 = if i == 0 { i32::MIN } else { nums1[(i-1) as usize] };
            let r1 = if i == len1 { i32::MAX } else { nums1[i as usize] };
            let l2 = if j == 0 { i32::MIN } else { nums2[(j-1) as usize]};
            let r2 = if j == len2 { i32::MAX } else { nums2[j as usize]};
            if l1 <= r2 {
                med1 = cmp::max(l1, l2);
                med2 = cmp::min(r1, r2);
                l = i + 1;
            } else {
                r = i - 1;
            }
        }
        if (len1 + len2) % 2 == 1 {
            med1 as f64
        } else {
            (med1 as f64 + med2 as f64) / 2.0
        }

    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::*;

    #[test]
    fn test4() {
        assert_eq!(Solution::find_median_sorted_arrays(vec![1,3], vec![2]), 2.0); 
        assert_eq!(Solution::find_median_sorted_arrays(vec![1,2,3], vec![4,5]), 3.0);
    }

}
