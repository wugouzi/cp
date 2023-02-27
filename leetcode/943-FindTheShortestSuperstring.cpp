//
// Created by wu on 2023/2/23.
//

#include "leetcode.h"

int over(string &s1, string &s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int m = min(n1, n2);
    int ans = m;
    while (ans) {
        string s = s1.substr(n1 - ans, ans);
        auto res = mismatch(s.begin(), s.end(), s2.begin());
        if (res.first == s.end())
            return ans;
        else
            ans--;
    }
    return ans;
}

string shortestSuperstring(vector<string>& words) {
    int n = words.size();
    vector<vector<int>> overlap(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                string &s1 = words[i];
                string &s2 = words[j];
                overlap[i][j] = over(s1, s2);
            }
        }
    }
    vector<vector<int>> dp(1<<n,vector<int>(n,-1));
    vector<vector<int>> pa(1<<n,vector<int>(n,-1));
    for (int i = 0; i < n; i++)
        dp[1<<i][i] = 0;
    for (int m = 0; m < (1 << n); m++) {
        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if (!(m & (1 << j))) {
                        int mm = m | (1 << j);
                        if (dp[mm][j] < dp[m][i] + overlap[i][j]) {
                            dp[mm][j] = dp[m][i] + overlap[i][j];
                            pa[mm][j] = i;
                        }
                    }
                }
            }
        }
    }
    int m = (1 << n) - 1;
    int t = 0;
    int ove = -1;
    for (int i = 0; i < n; i++)
        if (ove < dp[m][i]) {
            t = i;
            ove = dp[m][i];
        }
    string ans(words[t].rbegin(), words[t].rend());
    int sw, lt;
    while (1) {
        sw = m & ~(1 << t);
        lt = t;
        t = pa[m][t];
        if (t == -1)
            break;
        m = sw;
        for (int i = (int)words[t].size() - 1 - overlap[t][lt]; i >= 0; i--)
            ans.push_back(words[t][i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    //vector<string> s = {"alex","loves","leetcode"};
    vector<string> s = {"catg","ctaagt","gcta","ttca","atgcatc"};
    cout << shortestSuperstring(s);
}