//
// Created by wu on 2023/3/27.
//

#include "leetcode.h"

int countSubstrings(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    vector<vector<int>> dpl(n1+1, vector<int>(n2+1)), dpr(n1+1, vector<int>(n2+1));
    for (int i = 1; i < n1; i++)
        for (int j = 1; j < n2; j++)
            dpl[i][j] = s[i-1] == s[j-1] ? dpl[i-1][j-1] + 1 : 0;
    for (int i = n1-2; i >= 0; i--)
        for (int j = n2-2; j >= 0; j--)
            dpr[i][j] = s[i+1] == s[j+1] ? dpr[i+1][j+1] + 1 : 0;
    int ans = 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            if (s[i] != t[j])
                ans += (dpl[i][j] + 1) * (dpr[i][j] + 1);
    return ans;
}

int main(void) {
    cout << countSubstrings("aba", "baba");
}