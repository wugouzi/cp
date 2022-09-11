//
// Created by wu on 2022/8/23.
//

#include "leetcode.h"

int cnt(int s1, int s2) {
    return __builtin_popcount(s1 ^ s2) / 2;
}
int movesToChessboard(vector<vector<int>>& board) {
    int n = board.size();
    int c = (1 << n) - 1;
    int r1=-1, r2=-1, c1=-1, c2=-1;
    for (int i = 0; i < n; i++) {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < n; j++) {
            s1 <<= 1;
            s2 <<= 1;
            s1 |= board[i][j];
            s2 |= board[j][i];
        }
        if (r1 == -1) r1 = s1;
        if (s1 != r1 && r2 == -1) r2 = s1;
        if (s1 != r1 && s1 != r2) return -1;
        if (c1 == -1) c1 = s2;
        if (c1 != s2 && c2 == -1) c2 = s2;
        if (s2 != c1 && s2 != c2) return -1;
    }
    if (!((r1 & r2) == 0 && (r1 | r2) == c)) return -1;
    if (!((c1 & c2) == 0 && (c1 | c2) == c)) return -1;
    int t = 0;
    for (int i = 0; i < n; i++) {
        t <<= 1;
        t |= i % 2;
    }
    return min(cnt(c1, t), cnt(c2,t)) + min(cnt(r1,t),cnt(r2,t));
}

int main(void) {
    vector<vector<int>> nums = {{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
    cout << movesToChessboard(nums);
}