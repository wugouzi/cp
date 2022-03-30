//
// Created by wu on 2022/3/18.
//

#include "leetcode.h"

int lengthOfLongestSubstring(string s) {
    int left = -1, right = -1;
    int len = s.size();
    unordered_map<char, bool> mp;
    int ans = 0;
    while (++right < len) {
        char c = s[right];
        if (mp[c]) {
            while (s[++left] != c) {
                mp[left] = false;
            }
        }
        mp[c] = true;
        cout << "l: " << left << " r: " << right << endl;
        ans = max(ans, right - left);
    }
    return ans;
}

int main(void) {
    string s = "tmmzuxt";
    cout << lengthOfLongestSubstring(s);
}