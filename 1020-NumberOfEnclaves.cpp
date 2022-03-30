//
// Created by wu on 2022/3/15.
//

#include "leetcode.h"

int cnt, n, m;
bool out;
void draw(vector<vector<int>>& tp) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << tp[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}
void check(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (grid[i][j] == 0)  return;
    if (grid[i][j] == 1) {
        if (i == 0 || j == 0 || i == n-1 || j == m-1) {
            //cout << "out at " << i << ' ' << j << endl;
            out = true;
        }
        cnt++;
        grid[i][j] = 0;
        //draw(grid);
        check(grid,i+1,j);
        check(grid,i-1,j);
        check(grid,i,j+1);
        check(grid,i,j-1);
        //grid[i][j] = 0;
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int ans = 0;
    n = grid.size(), m = grid[0].size();
    draw(grid);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1) {
                cnt = 0;
                out = false;
                check(grid,i,j);
                ans += out ? 0 : cnt;
                //cout << ans << endl;
            }
    return ans;
}



int main(void) {
    vector<vector<int>> tp = {{0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1}};
    draw(tp);
    cout << numEnclaves(tp);
}