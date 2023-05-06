impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let mut dp = vec![vec![0; s.len()+1]; p.len() + 1];
        dp[0][0] = 1;
        for i in 1..s.len() + 1 {
            for j in 1..p.len() + 1 {
                if
            }
        }
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::is_match(), );
    }

}
