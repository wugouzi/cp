//
// Created by wu on 2022/3/11.
//

#include "leetcode.h"

vector<int> ans;
void qs(vector<pair<int,int>> &nums, int l, int r, int k) {
    int mid = (l+r)/2;
    swap(nums[mid], nums[r]);
    int L = l;
    int v = nums[r].first;
    for (int i = l; i < r; i++) {
        if (nums[i].first < v) {
            swap(nums[L++], nums[i]);
        }
    }
    swap(nums[L], nums[r]);
    if (L == nums.size() - k) {
        for (int i = L; i < nums.size(); i++)
            ans.push_back(nums[i].second);
    } else if (L < nums.size() - k)
        qs(nums, L + 1, r, k);
    else
        qs(nums, l, L - 1, k);
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> o;
    for (auto &n : nums)
        o[n]++;
    vector<pair<int,int>> t;
    for (auto &[k,v] : o)
        t.push_back(make_pair(v,k));
    qs(t, 0, t.size() - 1, k);
    return ans;
}

/*

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
}*/

int main(void) {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> tp = topKFrequent(nums, k);
    for (int i = 0; i < tp.size(); i++)
        cout << tp[i] << ' ';
}