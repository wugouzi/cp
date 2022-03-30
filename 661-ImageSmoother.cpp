//
// Created by wu on 2022/3/24.
//

#include "leetcode.h"

int n, m;
void comp(vector<vector<int>>& img, vector<vector<int>>& ans, int i, int j) {
    int sum = 0;
    int l = max(j-1,0), r = min(j+1,m-1), t = max(0, i-1), b = min(n-1, i+1);
    cout << l << ' ' << r << ' ' << t << ' ' << b << endl;
    for (int m = t; m <= b; m++)
        for (int n = l; n <= r; n++)
            sum += img[m][n];
    ans[i][j] = sum / (r-l+1) * (b-t+1);
}
vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    n = img.size();
    m = img[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            comp(img, ans, i, j);

    return ans;
}
int main(void) {
    vector<vector<int>> img = {{100,200,100},{200,50,200},{100,200,100}};
    vector<vector<int>> tp = imageSmoother(img);
}