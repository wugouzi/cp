//
// Created by wu on 2022/4/1.
//

#include "leetcode.h"

vector<int> tree;
int tn;
void add(int i) {
    while (i < tn) {
        tree[i]++;
        i += -i&i;
    }
}
int query(int i) {
    int sum = 0;
    while (i >= 1) {
        sum += tree[i];
        i -= i&-i;
    }
    return sum;
}
vector<int> countSmaller(vector<int>& nums) {
    vector<int> tp = nums;
    sort(tp.begin(), tp.end());
    tp.erase(unique(tp.begin(), tp.end()), tp.end());
    int n = nums.size();
    vector<int> ans;
    tree.resize(n+1);
    tn = n+1;
    for (auto& num : nums)
        num = lower_bound(tp.begin(), tp.end(), num) - tp.begin()+1;
    for (int i = n-1; i >= 0; i--) {
        ans.push_back(query(nums[i]-1));
        add(nums[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    vector<int> nums = {-1};
    vector<int> tp = countSmaller(nums);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}