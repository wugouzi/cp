//
// Created by wu on 2022/3/8.
//
#include "leetcode.h"

// vector<string> ans;
unordered_map<string,bool> mp;
bool check(string &s) {
    int c1 = 0, c2 = 0;
    for (auto &c : s) {
        if (c == '(') c1++;
        else c1++;
        if (c1 < c2) return false;
    }
    return c1 == c2;
}

void dfs(string &s, string &res, int i, int lc, int rc) {
    if (i == s.size()) {
        if (!lc && !rc && check(res)) mp[res];
        return;
    }
    if (s[i] == '(' || s[i] == ')')
        dfs(s, res, i+1, lc, rc);
    else {
        res.push_back(s[i]);
        dfs(s, res, i+1, lc, rc);
        res.pop_back();
    }
    if (s[i] == '(' && lc) {
        res.push_back('(');
        dfs(s, res, i+1, lc-1, rc);
        res.pop_back();
    }
    if (s[i] == ')' && rc && rc > lc) {
        res.push_back(')');
        dfs(s, res, i+1, lc, rc-1);
        res.pop_back();
    }
}
vector<string> removeInvalidParentheses(string s) {
    int l1 = 0, l2 = 0;
    for (auto &c : s) {
        if (c == '(') l1++;
        if (c == ')') {
            if (l1) l1--;
            else l2++;
        }
    }
    string tp;
    dfs(s, tp, 0, l1, l2);
    return ans;
}

/*
int len;
unordered_set<string> ans;
string s;
void foo(string cur, int i, int l, int r, int score) {
    if (cur.size() == len && l == r && score == 0) {
        ans.insert(cur);
        return;
    }
    if (i == s.size()) return;
    if (s[i] == '(') {
        foo(cur+"(", i+1,l+1,r,score+1);
        foo(cur,i+1,l,r,score);
    }
    else if (s[i] == ')') {
        if (l > r) foo(cur+")",i+1,l,r+1,score-1);
        foo(cur,i+1,l,r,score);
    } else foo(cur+s[i],i+1,l,r,score);
}
vector<string> removeInvalidParentheses(string _s) {
    int l = 0, r = 0;
    s = _s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') l++;
        else if (s[i] == ')' ) {
            if (l) {
                l--;
                len += 2;
            }
        } else len++;
    }
    foo("",0,0,0,0);
    vector<string> tp(ans.begin(),ans.end());
    return tp;
}
*/


int main(void) {
    string s = "()())()";
    //string s = "(a)())()";
    vector<string> tp = removeInvalidParentheses(s);
    for (int i = 0; i < tp.size(); i++) {
        cout << tp[i] << ' ';
    }
}
