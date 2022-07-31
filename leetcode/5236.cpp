//
// Created by wu on 2022/3/27.
//
#include "leetcode.h"

int minDeletion(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    int i;
    for (i = 0; i < n-1; i+=2) {
        if (i == n-2) {
            int a = 2;
        }
        while(i < n-1 && nums[i] == nums[i+1]) {
            i++;
            cnt++;
            if (i == n-2)
                cnt++;
        }
    }
    if (i == n-1)
        cnt++;
    return cnt;
}

int main(void) {
    vector<int> tp = {2,6,2,5,8,9,7,2,2,5,6,2,2,0,6,8,7,3,9,2,1,1,3,2,6,2,4,6,5,8,4,8,7,0,4,8,7,8,4,1,1,4,0,1,5,7,7,5,9,7,5,5,8,6,4,3,6,5,1,6,7,6,9,9,6,8,6,0,9,5,6,7,6,9,5,5,7,3,0,0,5,5,4,8,3,9,3,4,1,7,9,3,1,8,8,9,1,6,0,0};
    cout << minDeletion(tp);
}
