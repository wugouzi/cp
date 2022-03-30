//
// Created by wu on 2022/3/8.
//
#include <vector>
#include <string>

using namespace std;
vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<pair<int, int>> q;
    int l = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '|' && l == -1) l = i;
        else if (s[i] == '|') {
            if (i>i+1) q.push_back(make_pair(l,i));
            l = i;
        }
    }
    int n = q.size();
    vector<int> ans;
    for (auto&& c : queries) {
        int tp = 0;
        for (int i = 0; i < n; i++) {
            if (q[i].first >= c[0] && q[i].second <= c[1]) tp += q[i].second - q[i].first - 1;
            if (q[i].first >= c[1]) break;
        }
    }
    return ans;
}

int main(void) {
    string s = "**|**|***|";
    vector<vector<int>> q = {{2,5},{5,9}};

}