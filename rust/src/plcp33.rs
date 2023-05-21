use std::collections::BinaryHeap;

impl Solution {
    pub fn compute(a: i32, b: i32) -> i32 {
        ((b as f64 / a as f64) as f64).ceil() as i32
    }
    pub fn store_water(b: Vec<i32>, v: Vec<i32>) -> i32 {
        let mut b = b;
        let mut heap = BinaryHeap::new();
        let len = b.len();
        let mut cnt = 0;
        for i in 0..len {
            if v[i] == 0 {
                continue;
            }
            if b[i] == 0 {
                b[i] = 1;
                cnt += 1;
            }
            let m = (v[i] as f64 / b[i] as f64).ceil() as i32;
            heap.push((m, i));
        }
        if heap.is_empty() {
            return 0;
        }
        let mut res = i32::MAX;
        while res > cnt {
            let (c, i) = heap.pop().unwrap();
            res = res.min(cnt + c);
            if c == 1 {
                break;
            }
            let t = (v[i] + c - 2) / (c - 1);
            cnt += t - b[i];
            b[i] = t;
            heap.push((Self::compute(t, v[i]), i));
        }
        res
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use std::env;
    use super::*;

    #[test]
    fn testplcp33() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::store_water(vec![0], vec![0]), 0);
        assert_eq!(Solution::store_water(vec![1,3], vec![6,8]), 4);
        assert_eq!(Solution::store_water(vec![9,0,1], vec![0,2,2]), 3);
    }

}
