impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let strs: Vec<_> = strs.iter()
                               .map(|s| s.chars().collect())
                               .collect();
        let mut ans = &vec![];
        for (_, s) in strs.iter().enumerate() {
            if ans.len() == 0 {
                ans = s;
            } else {

            }
        }
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use std::env;
    use super::*;

    #[test]
    fn test() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::longest_common_prefix(), );
    }

}
