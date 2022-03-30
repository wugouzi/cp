//
// Created by wu on 2022/3/2.
//
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
int maximal(vector<vector<int>>&left, int col) {
    int wid = left.size();
    vector<int> l(wid), r(wid, wid);
    stack<int> s;
    for (int i = 0; i < wid; i++) {
        while(!s.empty() && left[s.top()][col] >= left[i][col]) {
            r[s.top()] = i;
            s.pop();
        }
        l[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    int vmax = 0;
    for (int i = 0; i < wid; i++) {
        vmax = max(vmax, left[i][col] * (r[i] - l[i] - 1));
    }
    return vmax;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> left(n, vector<int>(m));
    for (int i = 0; i < n; i++) left[i][0] = matrix[i][0] == '1';
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j ++)
            left[i][j] = matrix[i][j] == '1' ? 1 + left[i][j - 1] : 0;
    int vmax = 0;
    for (int i = 0; i < m; ++i) {
        vmax = max(vmax, maximal(left, i));
    }
    return vmax;
}

int main(void) {
    //vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    //vector<vector<char>> matrix = {{'0','1'}};
    vector<vector<char>> matrix = {{'0'}};
    //vector<vector<char>> matrix = {{'1'}};
    cout << maximalRectangle(matrix);
}