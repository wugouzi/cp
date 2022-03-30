//
// Created by wu on 2022/3/11.
//
#include "leetcode.h"
vector<int> s;
void check(vector<vector<int>>& child, int i) {
    int c1 = child[i][0], c2 = child[i][1];
    if (c1 == -1) s[i] = 1;
    else {
        check(child, c1);
        s[i] = 1 + s[c1];
        if (c2 != -1) {
            check(child, c2);
            s[i] += s[c2];
        }
    }
}
int countHighestScoreNodes(vector<int>& parents) {
    int n = parents.size();
    vector<vector<int>> child(n, vector<int>(2,-1));
    for (int i = 0; i < n; i++) {
        int p = parents[i];
        if (p == -1) continue;
        if (child[p][0] == -1) child[p][0] = i;
        else child[p][1] = i;

    }
    s.resize(n);
    check(child, 0);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int tp = 1;
        int c1 = child[i][0], c2 = child[i][1], c3 = parents[i];
        if (c1 != -1) tp *= s[c1];
        if (c2 != -1) tp *= s[c2];
        if (c3 != -1) tp *= n - s[i];
        if (ans == tp) cnt++;
        else if (ans < tp) {
            cnt = 1;
            ans = tp;
        }
    }
    return cnt;
}

int main(void) {
    vector<int> p = {-1,2,0};
    cout << countHighestScoreNodes(p);
}