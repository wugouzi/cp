//
// Created by wu on 2022/3/12.
//
#include "leetcode.h"

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int pn = p.size(), sn = s.size();
    if (pn > sn) return ans;

    vector<int> dif(26);
    int diff = 0;
    for (int i = 0; i < pn; i++) {
        dif[p[i]-'a']--;
        dif[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (dif[i])
            diff++;
    if (diff == 0) ans.push_back(0);
    for (int i = 0; i+pn < sn; i++) {
        if (dif[s[i]-'a'] == 1) diff--;
        if (dif[s[i]-'a'] == 0) diff++;
        dif[s[i]-'a']--;
        if (dif[s[i+pn]-'a'] == 0) diff++;
        if (dif[s[i+pn]-'a'] == -1) diff--;
        dif[s[i+pn]-'a']++;
        if (diff == 0) ans.push_back(i+1);
    }
    return ans;
}

int main(void) {
    string a = "bpaa";
    string b = "aa";
    vector<int> tp = findAnagrams(a, b);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}