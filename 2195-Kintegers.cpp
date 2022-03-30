//
// Created by wu on 2022/3/7.
//
#include <vector>
#include <iostream>

using namespace std;
long long minimalKSum(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    long long ans = 0;
    long long k = p;
    long long tp = nums[0];
    if (tp > 1) {
        if (k < tp) return (1+k)*k/2;
        ans += tp * (tp - 1) / 2;
        k -= tp - 1;
    }
    for (int i = 1; i < nums.size()&&k>0; i++) {
        tp = nums[i] - nums[i-1];
        if (tp > 1) {
            if (k < tp - 1) return ans + (nums[i-1]+1+nums[i-1]+k) * k / 2;
            ans += (nums[i-1]+1+nums[i]-1) * (tp-1) / 2;
            k -= tp - 1;
        }
    }
    if (k > 0) ans += (nums.back()+1+nums.back()+k)*k/2;
    return ans;
}

int main(void) {
    vector<int> nums = {53,41,90,33,84,26,50,32,63,47,66,43,29,88,71,28,83};
    int k = 76;
    cout << minimalKSum(nums, k);
}
