//
// Created by wu on 2022/3/6.
//
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int n = security.size();
    vector<int> l(n), r(n,n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && security[s.top()] >= security[i]) s.pop();
        l[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for (int i = n - 1; i > -1; i--) {
        while (!s.empty() && security[s.top()] >= security[i]) s.pop();
        r[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    vector<int> ans;
    for (int i = time > 0 ? time - 1 : 0; i < n; i++)
        if (i - l[i] - 1 >= time && r[i] - i - 1 >= time)
            ans.push_back(i);
    return ans;
}

int main(void) {
    vector<int> sec = {3,1,20,17,26,0,2,29,24};
    int time = 3;
    vector<int> tp = goodDaysToRobBank(sec, time);
    for (int i = 0; i < tp.size(); i++)
        cout << tp[i] << ' ';
}
