//
// Created by wu on 2022/3/8.
//
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;
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



int main(void) {
    string s = "(a)())()";
    vector<string> tp = removeInvalidParentheses(s);
    for (int i = 0; i < tp.size(); i++) {
        cout << tp[i] << ' ';
    }
}
