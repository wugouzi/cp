//
// Created by wu on 2022/9/28.
//

#include "leetcode.h"

vector<int> explorationSupply(vector<int>& station, vector<int>& pos) {
    int n = station.size();
    int m = pos.size();
    vector<pair<int,int>> p(m);
    for (int i = 0; i < m; i++)
        p[i] = make_pair(pos[i], i);
    sort(p.begin(), p.end());
    vector<int> ans(m);
    for (int i = 0, j = 0; i < m; i++) {
        ans[p[i].second] = j;
        while (j < n-1 && abs(station[j+1]-p[i].first) < abs(station[j]-p[i].first)) j++;
        ans[p[i].second] = j;
    }
    return ans;
}

int main(void) {
    vector<int> s{2,7,8,10};
    vector<int> p{4,9};
    vector<int> tp = explorationSupply(s, p);
    for (auto n : tp) cout << n << ' ';
}