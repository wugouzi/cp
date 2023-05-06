use std::cmp;
impl Solution {
    pub fn min_number_of_frogs(s: String) -> i32 {
        let (mut c, mut r, mut o, mut a) = (0, 0, 0, 0);
        let mut ans = 0;
        for d in s.chars() {
            match d {
                'c' => {
                    c += 1;
                    ans = cmp::max(ans, c);
                }
                'r' => {
                    r += 1;
                    ans = cmp::max(ans, r);
                    if r > c { return -1; }
                }
                'o' => {
                    o += 1;
                    ans = cmp::max(ans, o);
                    if o > r { return -1; }
                },
                'a' => {
                    a += 1;
                    ans = cmp::max(ans, a);
                    if a > o { return -1; }
                },
                'k' => {
                    c -= 1; r -= 1; o -= 1; a -= 1;
                    if c < 0 || r < 0 || o < 0 || a < 0 {
                        return -1;
                    }
                },
                _ => (),
            };
        }
        if c > 0 || r > 0 || o > 0 || a > 0 {
            -1
        } else {
            ans
        }
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::*;

    #[test]
    fn test1419() {
        assert_eq!(Solution::min_number_of_frogs("croakcroak".to_string()), 1);
        assert_eq!(Solution::min_number_of_frogs("crcoakroak".to_string()), 2);
        assert_eq!(Solution::min_number_of_frogs("croakcrook".to_string()), -1);
    }

}
