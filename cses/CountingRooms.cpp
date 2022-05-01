//
// Created by wu on 2022/4/30.
//

#include <iostream>
#include <vector>

using namespace std;
int n, m;

void check(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#')
        return;
    grid[i][j] = '#';
    check(grid,i+1,j);
    check(grid,i,j+1);
    check(grid,i-1,j);
    check(grid, i, j-1);
}

void pr(vector<vector<char>>&grid) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << endl;
    }
    cout << endl;
}

int main(void) {
    cin >> n >> m;
    int cnts = 0;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.') {
                check(grid, i, j);
                cnts++;
            }
    cout << cnts;
    return 0;
}