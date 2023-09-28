impl Solution {
    pub fn shortest_path_binary_matrix(grid: Vec<Vec<i32>>) -> i32 {
        if grid[0][0] == 1 {
            return -1;
        }
        let n = grid.len();
        let m = grid[0].len();
        if n == 1 && m == 1 {
            return 0;
        }
        let t = vec![0,-1,1];
        let mut dirs = vec![];
        for i in 0..3 {
            for j in 0..3 {
                dirs.push(vec![t[i],t[j]]);
            }
        }
        fn bfs(grid: &Vec<Vec<i32>>, i: usize, j: usize, vis: &mut Vec<Vec<bool>>,
               ans: &mut i32, dirs: &Vec<Vec<i32>>, k: i32) {
            if i == grid.len() - 1 && j == grid[0].len() - 1 {
                *ans = k;
                return;
            }
            vis[i][j] = true;
            for dir in dirs {
                let x = i as i32 + dir[0];
                let y = j as i32 + dir[1];
                if *ans == -1 && x >= 0 && y >= 0 &&
                    x < grid.len() as i32 && y < grid[0].len() as i32 &&
                    !vis[x as usize][y as usize] &&
                    grid[x as usize][y as usize] == 0 {
                        bfs(grid, x as usize, y as usize, vis, ans, dirs, k + 1);
                    }
            }
            vis[i][j] = false;
        }

        let mut vis = vec![vec![false; m]; n];
        let mut ans = -1;
        bfs(&grid, 0, 0, &mut vis, &mut ans, &dirs, 1);
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
    fn test1091() {
        env::set_var("RUST_BACKTRACE", "1");
        assert_eq!(Solution::shortest_path_binary_matrix(vec![vec![0,0,0],vec![1,1,0],vec![1,1,0]]), 4);
        assert_eq!(Solution::shortest_path_binary_matrix(vec![vec![1,0,0],vec![1,1,0],vec![1,1,0]]), -1);
    }

}
