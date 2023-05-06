impl Solution {

    pub fn reverse(x: i32) -> i32 {
        let mut x: i64 = x.into();
        let mut sign = 1;
        if x < 0 {
            x = -x;
            sign = -1;
        }
        let y = x.to_string()
            .chars()
            .rev()
            .collect::<String>()
            .parse::<i64>()
            .unwrap();
        println!("{x}, {y}");
        if y > i32::MAX as i64 {
            0
        } else {
            y as i32 * sign
        }
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::*;

    #[test]
    fn test7() {
        assert_eq!(Solution::reverse(123), 321);
        assert_eq!(Solution::reverse(-123), -321);
        assert_eq!(Solution::reverse(1534236469), 0);
        assert_eq!(Solution::reverse(-2147483648), 0);
    }

}
