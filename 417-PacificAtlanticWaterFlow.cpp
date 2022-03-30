//
// Created by wu on 2022/3/21.
//

#include "leetcode.h"

vector<vector<int>> ans;
vector<vector<bool>> P,A;
int n, m;
void check(vector<vector<int>>& heights, vector<vector<bool>>& sea, int i, int j) {
    if (sea[i][j]) return;
    if (i >= n || i < 0 || j >= m || j < 0) cout << i << ' ' << j;
    sea[i][j] = true;
    if (A[i][j] && P[i][j]) ans.push_back({i,j});
    if (i > 0 && heights[i-1][j] >= heights[i][j]) check(heights, sea, i-1, j);
    if (i < n-1 && heights[i+1][j] >= heights[i][j]) check(heights, sea, i+1, j);
    if (j > 0 && heights[i][j-1] >= heights[i][j]) check(heights, sea, i, j-1);
    if (j < m-1 && heights[i][j+1] >= heights[i][j]) check(heights, sea, i, j+1);
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    n = heights.size(); m = heights[0].size();
    P.resize(n, vector<bool>(m));
    A.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        if (!P[i][0])
            check(heights, P, i, 0);
        if (!A[i][m-1])
            check(heights, A, i, m-1);
    }
    for (int i = 0; i < m; i++) {
        if (!P[0][i])
            check(heights, P, 0, i);
        if (!A[n-1][i])
            check(heights, A, n-1, i);

    }
    return ans;
}
int main(void) {
    vector<vector<int>> tp = {{1,1},{1,1},{1,1}};
    tp = pacificAtlantic(tp);

}
