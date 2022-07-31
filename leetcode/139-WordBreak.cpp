//
// Created by wu on 2022/3/3.
//
#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;
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
}

int main(void) {
    //string s = "leetcode";
    //vector<string> d = {"leet", "code"};
    //string s = "applepenapple";
    //vector<string> d = {"apple","pen"};
    string s = "catsandog";
    vector<string> d = {"cats","dog","sand","and","cat"};
    cout << wordBreak(s, d);
}