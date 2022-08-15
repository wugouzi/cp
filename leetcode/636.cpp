//
// Created by wu on 2022/8/9.
//
#include "leetcode.h"
vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> ans(n);
    stack<pair<int,int>> st;
    for (auto& s : logs) {
        int i = 0, j;
        while (s[i] != ':') i++;
        int ind = stoi(s.substr(0, i));
        if (s[i+1] == 's') {
            int t = stoi(s.substr(i+7));
            st.push(make_pair(ind, t));
        } else {
            int t = stoi(s.substr(i+5));
            int tp = t - st.top().second + 1;
            ans[ind] += tp;
            st.pop();
            if (!st.empty())
                ans[st.top().first] -= tp;
        }
    }
    return ans;
}

int main(void) {
    vector<string> t = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<int> tp = exclusiveTime(2, t);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}