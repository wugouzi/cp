//
// Created by wu on 2022/4/4.
//

#include "leetcode.h"

int n;
int walk(vector<vector<int>>& matrix, int p) {
    int i = n-1, j = 0;
    int sum = 0;
    while (i >= 0) {
        while (j < n && matrix[i][j] <= p)
            j++;
        sum += j;
        i--;
    }
    return sum;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
    n = matrix.size();
    int l = matrix[0][0], r = matrix[n-1][n-1];
    while (l < r) {
        int med = l+r>= 0 ? (l+r)/2 : (l+r-1)/2;
        int val = walk(matrix, med);
        if (val < k) l = med+1;
        else r = med;
    }
    return l;
}

int main(void) {
    vector<vector<int>> m = {{-5,-4},{-5,-4}};
    int k = 2;
    cout << kthSmallest(m, k);
}