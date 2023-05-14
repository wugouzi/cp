use std::collections::HashMap;

impl Solution {
    pub fn rearrange_barcodes(b: Vec<i32>) -> Vec<i32> {
        let len = b.len();
        let mut ans = vec![0; len];
        for i in 0..len {
            ans[i] = i as i32;
        }
        let half = len as i32 / 2;
        let mut map: HashMap<i32, i32> = HashMap::new();
        for c in b.iter() {
            if let Some(k) = map.get(c) {
                map.insert(*c, k + 1);
            } else {
                map.insert(*c, 1);
            }
        }
        let (mut odd, mut even) = (1, 0);
        for (k, mut v) in map.into_iter() {
            while v > 0 && v <= half && odd < len {
                ans[odd] = k;
                v -= 1;
                odd += 2;
            }
            while v > 0 && even < len {
                ans[even] = k;
                v -= 1;
                even += 2;
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
    fn test1054() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::rearrange_barcodes(vec![1,1,1,2,2,2]), vec![2,1,2,1,2,1]);
    }

}
