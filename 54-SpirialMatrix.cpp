//
// Created by wu on 2022/3/23.
//

#include "leetcode.h"

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix[0].size(), n = matrix.size();
    int l = 0, r = m-1, t = 0, b = n-1;
    int s = 0;
    vector<int> ans(m*n);
    int k = m*n;
    int i = 0, j = 0;
    while (k) {
        if (s == 0 && j <= r) {
            ans[m*n-k] = matrix[i][j];
            j++;k--;
        } else if (s == 0) {
            s = 1;
            i++;j--;t++;
        } else if (s == 1 && i <= b) {
            ans[m*n-k] = matrix[i][j];
            i++;k--;
        } else if (s == 1) {
            s = 2;
            i--;j--;r--;
        } else if (s == 2 && j >= l) {
            ans[m*n-k] = matrix[i][j];
            j--;k--;
        } else if (s == 2) {
            s = 3;
            j++;i--;b--;
        } else if (s == 3 && i >= t) {
            ans[m*n-k] = matrix[i][j];
            i--;k--;
        } else if (s == 3) {
            s = 0;
            i++;j++;l++;
        }
    }
    return ans;
}

int main(void) {
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> tp = spiralOrder(m);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}