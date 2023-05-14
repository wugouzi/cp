impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s: Vec<_> = s.chars().collect();
        let p: Vec<_> = p.chars().collect();
        let mut dp = vec![vec![false; p.len()+1]; s.len() + 1];
        dp[0][0] = true;
        let mm = | x: usize, y: usize | {
            if x == 0 {
                false
            } else if p[y-1] == '.' {
                true
            } else {
                s[x-1] == p[y-1]
            }
        };
        
        for i in 0..s.len() + 1 {
            for j in 1..p.len() + 1 {
                if p[j-1] == '*' {
                    dp[i][j] = dp[i][j-2];
                    if mm(i, j-1) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                } else {
                    if mm(i, j) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
        dp[s.len()][p.len()]

    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::*;
    use std::env;

    #[test]
    fn test10() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::is_match("aa".to_string(), "a".to_string()), false);
        assert_eq!(Solution::is_match("aa".to_string(), "a*".to_string()), true);
        assert_eq!(Solution::is_match("ab".to_string(), ".*".to_string()), true);
    }

}
