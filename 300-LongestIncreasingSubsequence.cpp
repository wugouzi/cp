//
// Created by wu on 2022/3/8.
//
#include <vector>
#include <iostream>

using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans = {nums[0]};
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back())
            ans.push_back(nums[i]);
        else if (nums[i] < ans.back()) {
            int l = 0, r = ans.size() - 1;
            int p = r;
            while (l <= r) {
                int med = (l+r)/2;
                if (ans[med] == nums[i]) {
                    p = med;
                    break;
                } else if (ans[med] < nums[i]) {
                    l = med+1;
                }
                else if (ans[med] > nums[i]) {
                    r = med-1;
                    p = med;
                }
            }
            ans[p] = nums[i];

        }
        for (int t = 0; t < ans.size(); t++) cout << ans[t] << ' ';
        cout << endl;
    }
    return ans.size();
        /*vector<int> ans = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) ans.push_back(nums[i]);
            else {
                int l = 0, r = ans.size() - 1, pos = -1;
                while(l <= r) {
                    int med = (l+r)/2;
                    if (ans[med] < nums[i]) {
                        pos = med;
                        l = med+1;
                    }
                    else if (ans[med] > nums[i]) r = med-1;
                    else {
                        pos = med-1;
                        break;
                    }
                }
                ans[pos+1] = nums[i];
            }
        }
        return ans.size();*/
}

int main(void) {
    vector<int> nums = {18,55,66,2,3,54};
    cout << lengthOfLIS(nums);
}