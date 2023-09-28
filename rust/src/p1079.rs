use std::collections::HashMap;


// C^n_k = C^{n-1}_{k-1} + C^{n-1}_k
impl Solution {
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let mut map = HashMap::new();
        for c in tiles.chars().into_iter() {
            *map.entry(c).or_insert(0) += 1;
        }
        let cnts: Vec<_> = map.values().collect();
        let (n, m) = (tiles.len(), cnts.len());
        let mut dp = vec![vec![0; m+1]; n+1];
        let mut C = vec![vec![1; n+1]; n+1];
        for i in 2..n+1 {
            for j in 2..n+1 {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
        for i in 0..m {
            for j in
        }

        for j in 0..*cnts[0] {
            dp[0][j] = 1;
        }
        let mut sum = *cnts[0];
        for i in 1..m {
            for j in 1..
        }
        0
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
        assert_eq!(Solution::num_tile_possibilities("AAB"), 8);
    }

}
