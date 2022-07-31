//
// Created by wu on 2022/5/28.
//

#include "leetcode.h"

string removeOuterParentheses(string s) {
    if (s.size() == 0) return "";
    if (s.size() == 2) return s;
    int l = 1;
    string ans;
    int li = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(')
            l++;
        if (s[i] == ')')
            l--;
        if (l == 0) {
            if (i == s.size()-1 && li == 0)
                return removeOuterParentheses(s.substr(1,s.size()-2));
            else {
                ans += removeOuterParentheses(s.substr(li,i-li+1));
                li = i+1;
            }
        }
    }
    return ans;

}

int main(void) {
    string s = "(()())(())";
    cout << removeOuterParentheses(s);
}