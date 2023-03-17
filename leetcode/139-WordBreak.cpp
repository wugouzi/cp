//
// Created by wu on 2022/3/3.
//
#include "leetcode.h"

class Trie {
public:
    bool end = 0;
    unordered_map<char,Trie*> mp;
} *tree;
void insert(string s) {
    Trie *tp = tree;
    for (auto &c : s) {
        if (!tp->mp.count(c))
            tp->mp[c] = new Trie();
        tp = tp->mp[c];
    }
    tp->end = 1;
}
bool check(string &s, int l, int r) {
    Trie *tp = tree;
    for (int i = l; i <= r; i++)
        if (tp->mp.count(s[i]))
            tp = tp->mp[s[i]];
        else
            return false;
    return tp->end;
}
bool wordBreak(string s, vector<string>& wordDict) {
    tree = new Trie();
    int n = s.size();
    vector<int> dp(n+1);
    dp[0] = true;
    for (auto &w : wordDict)
        insert(w);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && check(s, j, i-1)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

/*
bool wordBreak(string s, vector<string>& wordDict) {
    int maxl = 0;
    int minl = 100;
    unordered_set<string> strs;
    for (auto&& str : wordDict) {
        int val = str.size();
        maxl = max(maxl, val);
        minl = min(minl, val);
        strs.insert(str);
    }
    int n = s.size();
    vector<bool> tp(n+1);
    tp[0] = true;
    for (int i = minl; i < n+1; i++) {
        for (int j = i - minl; j >= i-maxl&& j>=0; j--)
            if (tp[j] &&
                strs.find(s.substr(j, i-j)) != strs.end()) {
                tp[i] = true;
                break;
            }

    }
    return tp[n];
}*/

int main(void) {
    //string s = "leetcode";
    //vector<string> d = {"leet", "code"};
    //string s = "applepenapple";
    //vector<string> d = {"apple","pen"};
    string s = "leetcode";
    vector<string> d = {"leet","code"};
    cout << wordBreak(s, d);
}