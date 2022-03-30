//
// Created by wu on 2022/3/15.
//
#include "leetcode.h"



int n,m;
bool check(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < m && grid2[i][j] == 1) {
        bool t1 = grid1[i][j] < grid2[i][j];
        grid2[i][j] = 0;
        bool tp =  check(grid1,grid2,i+1,j) & check(grid1,grid2,i-1,j) & check(grid1,grid2,i,j-1) & check(grid1,grid2,i,j+1);
        if (t1) return false;
        return tp;
    }
    return true;
}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    n = grid1.size();
    m = grid1[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid2[i][j] == 1)
                cnt += check(grid1, grid2, i, j) ? 1 : 0;
    return cnt;
}

int main(void) {
    vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}}, grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    cout << countSubIslands(grid1, grid2);
}