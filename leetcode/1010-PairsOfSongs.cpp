//
// Created by wu on 2023/3/25.
//

#include "leetcode.h"

int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<int,int> mp;
    for (auto &n : time)
        mp[n % 60]++;
    int ans = 0;
    for (auto &[k,v] : mp) {
        if (k == 30 || k == 0) {
            ans += mp[k] * (mp[k]-1) / 2;
        }
        else if (k < 30 && mp.count(60-k)) {
            ans += mp[k] * mp[60 - k];
        }
    }
    return ans;
}

int main(void) {
    vector<int> t{70,311,74,427,232,211,126,83,357,118,97,428};
    cout << numPairsDivisibleBy60(t);
}
