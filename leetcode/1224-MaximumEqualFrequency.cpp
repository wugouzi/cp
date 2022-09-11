//
// Created by wu on 2022/8/18.
//

#include "leetcode.h"

int maxEqualFreq(vector<int>& nums) {
    unordered_map<int,int> cnt, freq;
    int maxfreq = 0, ans = -1;
    for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        if (cnt[n] > 0) {
            freq[cnt[n]]--;
        }
        cnt[n]++;
        freq[cnt[n]]++;
        maxfreq = max(maxfreq, cnt[n]);
        bool ok = maxfreq == 1||
                  (freq[maxfreq] * maxfreq + freq[maxfreq-1] * (maxfreq-1) == i + 1 &&
                   (freq[maxfreq] == 1 || freq[maxfreq-1] == 1));
        if (ok)
            ans = max(ans, i + 1);
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1,1,1,2,2,2,3,3,3,4,4,4,5};
    cout << maxEqualFreq(nums);
}