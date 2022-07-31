//
// Created by wu on 2022/4/8.
//

#include "leetcode.h"

int longestSubstring(string s, int k) {
    int ans = 0;
    int n = s.size();
    int l,r;
    bool check;
    int len = min(26, n);
    unordered_map<char, int> mp;
    for (int kinds = 1; kinds <= len; kinds++) {
        mp.clear();
        l = -1, r = 0;
        while (r < n) {
            mp[s[r]]++;
            while (mp.size() > kinds) {
                mp[s[++l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
            }
            check = true;
            for (auto& [_, c] : mp)
                if (c < k) {
                    check = false;
                    break;
                }
            if (check)
                ans = max(ans, r-l);
            r++;
        }
    }
    return ans;
}

int main(void) {
    string s = "aaabb";
    int k = 3;
    cout << longestSubstring(s, k);
}