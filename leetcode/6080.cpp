//
// Created by wu on 2022/5/29.
//

#include "leetcode.h"
int totalSteps(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n);
    stack<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        while (s.size() && nums[s.top()] <= nums[i]) {
            cur = max(cur,f[s.top()]);
            s.pop();
        }
        if (s.size()) {
            f[i] = cur+1;
            ans = max(f[i],ans);
        }
        s.push(i);
    }
    return ans;
}

int main(void){
    vector<int> tp = {5,3,4,4,7,3,6,11,8,5,11};
    cout << totalSteps(tp);
}