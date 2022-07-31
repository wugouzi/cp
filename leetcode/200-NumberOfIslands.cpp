//
// Created by wu on 2022/3/5.
//

#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
int kn, km;
void check(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    for (auto&& dir : dirs) {
        int newi = i + dir[0], newj = j + dir[1];
        if (newi < kn && newi > -1 && newj < km && newj > -1 && grid[newi][newj] == '1' && !visited[newi][newj])
            check(grid, visited, newi, newj);
    }
}
int numIslands(vector<vector<char>>& grid) {
    kn = grid.size();
    km = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited(kn, vector<bool>(km));
    for (int i = 0; i < kn; i++) {
        for (int j = 0; j < km; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                ans++;
                check(grid, visited, i, j);
            }
        }
    }
    return ans;
}

int main(void) {
    vector<vector<char>> grid = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    //vector<vector<char>> grid = {{'1','1','0'},{'1','0','0'},{'0','1','1'}};
    cout << numIslands(grid);
}
