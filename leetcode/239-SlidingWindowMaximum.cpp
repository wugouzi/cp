//
// Created by wu on 2022/3/7.
//
#include <vector>
//#include <pair>
#include <queue>
#include <iostream>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<pair<int,int>> q;

    for (int i = 0; i < k; i++) {
        while (!q.empty() && q.back().second < nums[i]) q.pop_back();
        q.push_back(make_pair(i, nums[i]));
    }
    vector<int> ans;
    ans.push_back(q.front().second);
    for (int i = k; i < n; i++) {
        if (q.front().first == i - k) q.pop_front();
        while (!q.empty() && q.back().second < nums[i]) q.pop_back();
        q.push_back(make_pair(i, nums[i]));
        ans.push_back(q.front().second);
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1,-1};
    int k = 1;
    vector<int> tp = maxSlidingWindow(nums, k);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}