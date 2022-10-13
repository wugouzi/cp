//
// Created by wu on 2022/10/13.
//

#include "leetcode.h"
vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    int s = -1;
    for (int i = 0; i < n; i++)
        if (nums[i] == 1) {
            s = i;
            break;
        }
    vector<vector<int>> son(n);
    for (int i = 0; i < n; i++)
        if (parents[i] != -1)
            son[parents[i]].push_back(i);
    if (s == -1)
        return ans;
    unordered_map<int,bool> mp;
    queue<int> q;
    function<void(int)> dfs = [&](int i) {
        mp[nums[i]] = true;
        for (auto &t : son[i])
            dfs(t);
    };
    int tp = 2;
    int ori = -1;
    while (s != -1) {
        for (auto &oo : son[s])
            if (oo != ori)
                dfs(oo);
        ori = s;
        mp[nums[s]] = true;
        while (mp.count(tp)) tp++;
        ans[s] = tp;
        s = parents[s];
    }
    return ans;
}

int main(void) {
    vector<int> p{-1,0,1,0,3,3};
    vector<int> n{5,4,6,2,1,3};
    auto tp = smallestMissingValueSubtree(p,n);
    for (auto &n : tp) cout << n << ' ';
}