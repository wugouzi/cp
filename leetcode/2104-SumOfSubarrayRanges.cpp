//
// Created by wu on 2022/3/4.
//

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long summin = 0, summax = 0;
    long long res = 0;
    vector<int> minl(n), minr(n), maxl(n), maxr(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while(!s.empty() && nums[s.top()] > nums[i]) s.pop();
        minl[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for (int i = n - 1; i > -1; i--) {
        while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
        minr[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for (int i = 0; i < n; i++) {
        while(!s.empty() && nums[s.top()] < nums[i]) s.pop();
        maxl[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for (int i = n - 1; i > -1; i--) {
        while(!s.empty() && nums[s.top()] <= nums[i]) s.pop();
        maxr[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    for (int i = 0; i < n; i++) {
        res += ((long long)maxr[i] - i) * (i - maxl[i]) * nums[i];
        res -= ((long long)minr[i] - i) * (i - minl[i]) * nums[i];
    }
    return res;
}

int main(void) {
    vector<int> nums = {1,3,3};
    cout << subArrayRanges(nums);
}