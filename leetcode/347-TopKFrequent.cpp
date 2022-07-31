//
// Created by wu on 2022/3/11.
//

#include "leetcode.h"

static bool cmp(pair<int, int>& t1, pair<int, int>& t2) {
    return t1.second > t2.second;
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++) m[nums[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> tp(cmp);
    for (auto& c : m) {
        if (tp.size() < k || tp.top().second < c.second) {
            if (tp.size() == k) tp.pop();
            tp.push(c);
        }
    }
    vector<int> ans;
    while (!tp.empty()) {
        ans.push_back(tp.top().first);
        tp.pop();
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> tp = topKFrequent(nums, k);
    for (int i = 0; i < tp.size(); i++)
        cout << tp[i] << ' ';
}