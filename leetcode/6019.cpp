//
// Created by wu on 2022/3/6.
//

#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>


using namespace std;
gcd(1,3);
vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ans;
    if (nums.size() == 1) return nums;
    int i;
    for (i = 0; i < nums.size()-1; i++) {
        int tp = nums[i];
        while(gcd(tp, nums[i+1]) > 1 && i < nums.size() - 1) {
            tp = lcm(tp,nums[i+1]);
            i++;
        }
        ans.push_back(tp);
    }
    if (i == nums.size()-1) ans.push_back(nums.back());
    return ans;
}

int main(void) {
    vector<int> nums = {602,37963,37963,37963};
}