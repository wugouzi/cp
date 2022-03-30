//
// Created by wu on 2022/3/19.
//
#include "leetcode.h"

int solution(vector<int> &A, int R) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    int tcnt = 0;
    int ans = 0;
    int tp = 0;
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[A[i]]++;
        if (mp[A[i]] == 1) tcnt++;
    }
    tp = tcnt;
    for (int i = 0; i < R; i++) {
        mp[A[i]]--;
        if (mp[A[i]] == 0) tp--;
    }
    ans = tp;
    for (int i = 1; i + R - 1 < n; i++) {
        if (mp[A[i-1]] == 0)
            tp++;
        mp[A[i-1]]++;
        if (mp[A[i+R-1]] == 1)
            tp--;
        mp[A[i+R-1]]--;
        ans = max(ans, tp);
    }
    return ans;
}

int main(void) {
    vector<int> nums = {2,1,2,3,2,2};
    int k = 3;
    cout << solution(nums, k);
}
