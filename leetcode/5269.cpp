//
// Created by wu on 2022/3/27.
//
#include "leetcode.h"

int vmax;
int n;
void maxv(vector<vector<int>>& p, vector<int>& ind, int k, int sum) {
    if (k == 0 && vmax < sum)
        vmax = sum;
    for (int i = 0; i < n; i++) {
        int tp = sum + p[i][ind[i]];
        if (ind[i] >= p[i].size()) continue;
        ind[i]++;
        maxv(p, ind, k-1, tp);
        ind[i]--;
    }
}
int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    vmax = 0;
    n = piles.size();
    vector<int> ind(n);
    maxv(piles, ind, k, 0);
    return vmax;
}

int main(void) {
    vector<vector<int>> tp = {{100},{100},{100},{100},{100},{100},{1,1,1,1,1,1,700}};
    int k = 7;
    cout << maxValueOfCoins(tp, k);
}
