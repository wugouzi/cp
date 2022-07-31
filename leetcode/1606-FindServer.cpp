//
// Created by wu on 2022/3/30.
//

#include "leetcode.h"

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    set<int> avai;
    using Pair = pair<int, int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> busy;
    vector<int> cnt(k);
    for (int i = 0; i < k; i++) avai.insert(i);
    for (int i = 0; i < arrival.size(); i++) {
        while(!busy.empty() && busy.top().first <= arrival[i]) {
            avai.insert(busy.top().second);
            busy.pop();
        }
        if (avai.empty()) continue;
        auto p = avai.lower_bound(i%k);
        if (p == avai.end())
            p = avai.begin();
        cnt[*p]++;
        busy.emplace(arrival[i]+load[i], *p);
        avai.erase(p);
    }
    vector<int> ans = {0};
    for (int i = 1; i < k; i++)
        if (cnt[i] > cnt[ans[0]]) {
            ans.clear();
            ans.push_back(i);
        } else if (cnt[i] == cnt[ans[0]])
            ans.push_back(i);
    return ans;
}

int main(void) {
    int k = 2;
    vector<int> arr = {1,2,3};
    vector<int> load = {10000,1,10000};
    vector<int> tp = busiestServers(k, arr, load);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}