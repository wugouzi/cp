//
// Created by wu on 2022/11/5.
//

#include "leetcode.h"

vector<string> substrings(string s) {
    vector<string> subs;
    int i = 2;
    int n = s.size();
    while (i < n - 1) {
        int cnt = 0;
        int j = i;
        while (1) {
            if (cnt == 0 && (s[j] == ',' || j >= n - 1)) {
                break;
            }
            if (s[j] == '(') cnt++;
            if (s[j] == ')') cnt--;
            j++;
        }
        subs.push_back(s.substr(i, j-i));
        i = j+1;
    }
    return subs;
}
bool parseBoolExpr(string e) {
    if (e[0] == 't') return true;
    if (e[0] == 'f') return false;
    vector<string> subs = substrings(e);
    if (e[0] == '!') {
        return !parseBoolExpr(subs[0]);
    } else if (e[0] == '&') {
        for (auto &s : subs) {
            if (!parseBoolExpr(s)) {
                return false;
            }
        }
        return true;
    } else if (e[0] == '|') {
        for (auto &s : subs) {
            if (parseBoolExpr(s)) {
                return true;
            }
        }
        return false;
    }
    return true;
}

int main(void) {
    cout << 0 + parseBoolExpr("!(&(f,t))");
}