//
// Created by wu on 2022/2/27.
//
#include <vector>

using namespace std;
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
}

int main(void) {
    vector<int> tp = {2,3,6,7};
    auto tpp = combinationSum(tp, 7);
}
