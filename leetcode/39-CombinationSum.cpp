//
// Created by wu on 2022/2/27.
//
#include "leetcode.h"

vector<vector<int>> help(vector<int>& candidates, int target, int i) {
    vector<vector<int>> ans;
    vector<int> base;
    if (i >= candidates.size()) return vector<vector<int>>();
    if (target < candidates[i]) return vector<vector<int>>();
    for (int sum = 0; sum <= target; sum += candidates[i], base.push_back(candidates[i])) {
        if (sum == target) {
            ans.push_back(base);
        } else {
            vector<vector<int>> tp = help(candidates, target - sum, i+1);
            for (auto v : tp) {
                v.insert(v.begin(), base.begin(), base.end());
                ans.push_back(v);
            }
        }

    }
    return ans;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return help(candidates, target, 0);
}
/*
vector<vector<int>> search(vector<int>& candidates, int target, int m) {
    vector<vector<int>> ans;
    for (const int& i : candidates) {
        if (i < target && i >= m) {
            vector<vector<int>> tp = search(candidates, target - i, i);
            for (auto&& j : tp) {
                j.push_back(i);
                ans.push_back(j);
            }
        } else if (i == target && i >= m) {
            ans.push_back({i});
        }
    }
    return ans;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    return search(candidates, target, -1);
}*/

int main(void) {
    vector<int> tp = {2,3,6,7};
    auto tpp = combinationSum(tp, 7);
    for (auto &vv : tpp) {
        for (auto &v : vv) cout << v << ' ';
        cout << endl;
    }
}
