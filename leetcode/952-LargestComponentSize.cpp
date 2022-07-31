//
// Created by wu on 2022/7/30.
//

#include "leetcode.h"

vector<int> pa;
int find(int x) {
    while (pa[x] != x) {
        pa[x] = pa[pa[x]];
        x = pa[x];
    }
    return x;
}
void uni(int x, int y) {
    int px = find(x), py = find(y);
    pa[py] = px;
}
int largestComponentSize(vector<int>& num) {
    int m = *max_element(num.begin(), num.end());
    int n = num.size();
    pa.resize(m+1);
    for (int i = 0; i <= m; i++) pa[i] = i;
    for (auto& n : num) {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                uni(n, i);
                uni(n, n/i);
            }
    }
    vector<int> cnts(m+1);
    int ans = 0;
    for (auto& n : num) {
        int tp = find(n);
        ans = max(ans, ++cnts[tp]);
    }
    return ans;
}

int main(void) {
    vector<int> nums = {4,6,15,35};
    cout << largestComponentSize(nums);
}