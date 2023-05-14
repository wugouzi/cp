impl Solution {
    pub fn query_string(s: String, n: i32) -> bool {
        let mut base = 0;
        for c in s.chars().rev().into_iter() {
            match c {
                '0' => base <<= 1,
                '1' => base = (base << 1) + 1,
                _ => {}
            };
        }
        // println!("{base}");
        for i in n / 2 + 1 .. n + 1 {
            let mut suc = false;
            let mut j = i;
            while j <= base {
                if () ^ j == 0  {
                    suc = true;
                    break;
                }
                j <<= 1;
            }
            if !suc {
                // println!("fail in {i}");
                return false;
            }

        }
        true
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use std::env;
    use super::*;

    #[test]
    fn test1016() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::query_string("0110".to_string(), 3), true);
        assert_eq!(Solution::query_string("0110".to_string(), 4), false);
    }

}
