//
// Created by wu on 2022/3/30.
//

#include "leetcode.h"

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> cnt(k), free(k);
    for (int i = 0; i < arrival.size(); i++) {
        int j = i % k;
        while (j < i + k && free[j%k] > arrival[i]) j++;
        if (j == i + k)
            continue;
        free[j] += load[i];
        cnt[j]++;
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
    int k = 3;
    vector<int> arr = {1,2,3,4,8,9,10};
    vector<int> load = {5,2,10,3,1,2,2};
    vector<int> tp = busiestServers(k, arr, load);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}