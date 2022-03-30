//
// Created by wu on 2022/3/19.
//

#include "leetcode.h"

vector<int> tmax;
vector<int> curmax;
int n, m;
vector<vector<int>> dirs = {{1,0}, {-1,0},{0,1},{0,-1}};
void check(vector< vector<int> > &Board, int i, int j, int d) {
    if (d > 3 || i < 0 || j < 0 || i >= n || j >= m) cout << d << ' ' << i << ' ' << j << endl;
    curmax[d] = Board[i][j];
    if (d == 3 && tmax < curmax) {
        tmax = curmax;
        Board[i][j] = curmax[d];
        return;
    } else if (d == 3)
        return;
    Board[i][j] = -1;
    for (auto& dir : dirs) {
        int newi = i + dir[0], newj = j + dir[1];
        if (newi >= 0 && newj >= 0 && newi < n && newj < m && Board[newi][newj] != -1) {
                check(Board, newi, newj, d+1);
        }
    }
    Board[i][j] = curmax[d];
}
int solution(vector< vector<int> > &Board) {
    // write your code in C++14 (g++ 6.2.0)
    tmax = {0,0,0,0};
    n = Board.size();
    m = Board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Board[i][j] >= tmax[0]) {
                curmax = {0,0,0,0};
                check(Board, i, j, 0);
            }
        }
    }
    return 1000 * tmax[0] + 100 * tmax[1] + 10 * tmax[2] + tmax[3];
}

int main(void) {
    vector<vector<int>> board = {{1,1,1},{1,3,4},{1,4,3}};
    cout << solution(board);
}