//
// Created by wu on 2022/8/4.
//

#include "leetcode.h"

vector<int> minSubsequence(vector<int>& nums) {
    vector<pair<int,int>> nums2, nums3;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        nums2.push_back(make_pair(nums[i], i));
        sum += nums[i];
    }
    sort(nums2.begin(), nums2.end());
    int sum2 = 0;
    for (int i = nums2.size()-1; 2*sum2 <= sum; i--) {
        sum2 += nums2[i].first;
        nums3.push_back(make_pair(nums2[i].second, nums2[i].first));
    }
    sort(nums3.begin(), nums3.end());
    vector<int> ans;
    for (int i = 0; i < nums3.size(); i++)
        ans.push_back(nums3[i].second);
    return ans;
}

int main(void) {
    vector<int> nums = {4,4,7,6,7};
    vector<int> tp = minSubsequence(nums);
    for (int i = 0; i <= tp.size(); i++) cout << tp[i] << endl;
}