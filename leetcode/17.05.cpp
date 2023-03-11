//
// Created by wu on 2023/3/11.
//

#include "leetcode.h"

vector<string> findLongestSubarray(vector<string>& array) {
    int n = array.size();
    vector<int> pre(n);
    pre[0] = 1 - 2 * (array[0][0] >= '0' && array[0][0] <= '9');
    unordered_map<int,int> mp;
    mp[0] = -1;
    int len = 0, l = 0;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i-1] + 1 - 2 * (array[i][0] >= '0' && array[i][0] <= '9');
        if (!mp.count(pre[i]))
            mp[pre[i]] = i;
        else if (i - mp[pre[i]] > len) {
            len = i - mp[pre[i]];
            l = pre[i] + 1;
        }
    }
    vector<string> ans(array.begin() + l, array.begin() + l + len);
    return ans;
}

int main(void) {
    vector<string> t{"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    for (auto &tp : findLongestSubarray(t)) cout << tp << ' ';
}