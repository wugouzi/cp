//
// Created by wu on 2022/4/10.
//

#include "leetcode.h"

string smallestSubsequence(string s) {
    int mask = 0;
    string ans;
    unordered_map<char, int> mp;
    for (auto& c : s)
        mp[c]++;
    for (auto& c : s) {
        if (mask&(1<<c-'a')) {
            mp[c]--;
            continue;
        }
        char ch = ans.back();
        while (!ans.empty() && mp[ch]>1 && ch > c) {
            mp[ch]--;
            mask &= -1^(1<<(ch-'a'));
            ans.pop_back();
            ch = ans.back();
        }
        ans.push_back(c);
        mask |= 1 << (c-'a');
    }
    return ans;
}

int main(void) {
    string s = "baababaaaaababbbbbbaababaababa";
    cout << smallestSubsequence(s);
}