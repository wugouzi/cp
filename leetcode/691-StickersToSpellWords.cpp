//
// Created by wu on 2022/5/14.
//
#include "leetcode.h"

vector<int> dp;
int cnts[50][26];
int m,n;
string tar;
int dpp(int mask) {
    if (mask == 0)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    dp[mask] = n+1;
    for (int i = 0; i < m; i++) {
        int left = mask;
        int cnt[26];
        memset(cnt,0, sizeof(cnt));
        for (int j = 0; j < n; j++) {
            if (mask&(1<<j)&&cnts[i][tar[j]-'a']>cnt[tar[j]-'a']) {
                cnt[tar[j]-'a']++;
                left ^= 1<<j;
            }
        }
        if (left < mask)
            dp[mask] = min(dp[mask],1+dpp(left));
    }
    return dp[mask];
}
int minStickers(vector<string>& stickers, string target) {
    n = target.size();
    tar = target;
    dp.resize(1<<n,-1);
    memset(cnts,0,sizeof(cnts));
    m = stickers.size();
    for (int i = 0; i < stickers.size(); i++)
        for (auto& c : stickers[i])
            cnts[i][c-'a']++;
    int ans = dpp((1<<n)-1);
    return ans <= n ? ans : -1;
}

int main(void) {
    vector<string> s = {"with","example","science"};
    string ss = "thehat";
    cout << minStickers(s,ss);
}
