use std::collections::HashMap;

impl Solution {
    fn help(n: i32, edges: &Vec<Vec<i32>>, target: i32, p: f64, ans: &mut f64,
            level: i32, k: i32, vis: &mut HashMap<i32, bool>
    ) {
        println!("Check {n}, {p}");
        if k == level {
            if n == target {
                *ans = p;
            }
            return;
        }
        let mut t = edges[n as usize].len();
        if n != 0 {
            t -= 1;
        }
        if t == 0 {
            Self::help(n ,edges, target, p, ans, level, level, vis);
            return;
        }

        let p = p / t as f64;
        vis.insert(n, true);
        for i in &edges[n as usize] {
            if let Some(_) = vis.get(i) {
                continue;
            }
            Self::help(*i, edges, target, p, ans, level, k+1, vis);
        }
        vis.remove(&n);
    }
    pub fn frog_position(n: i32, edges: Vec<Vec<i32>>, t: i32, target: i32) -> f64 {
        let mut edge: Vec<Vec<i32>> = vec![vec![]; n as usize];
        for v in &edges {
            edge[(v[0]-1) as usize].push(v[1]-1);
            edge[(v[1]-1) as usize].push(v[0]-1);
        }
        let mut ans = 0 as f64;
        let mut vis: HashMap<i32, bool> = HashMap::new();
        Self::help(0, &edge, target - 1, 1.0, &mut ans, t, 0, &mut vis);
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
    fn test1377() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::frog_position(7, vec![vec![1,2],vec![1,3],vec![1,7],vec![2,4],vec![2,6],vec![3,5]], 20, 6), 1.0/6.0);
        assert_eq!(Solution::frog_position(7, vec![vec![1,2],vec![1,3],vec![1,7],vec![2,4],vec![2,6],vec![3,5]], 2, 4), 1.0/6.0);
        assert_eq!(Solution::frog_position(7, vec![vec![1,2],vec![1,3],vec![1,7],vec![2,4],vec![2,6],vec![3,5]], 1, 7), 1.0/3.0);
    }

}
