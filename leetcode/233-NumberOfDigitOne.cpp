//
// Created by wu on 2022/4/29.
//
#include "leetcode.h"

const int ndgit = 13;
int dp[ndgit][ndgit][2];
int vc[10], sc;
void init(int c) {
    for (int i = 0; i < ndgit; i++)
        for (int j = 0; j < ndgit; j++)
        dp[i][j][0] = dp[i][j][1] = -1;
    string s = to_string(c);
    sc = s.size();
    for (int i = 0; i < sc; i++)
        vc[i] = s[i]-'0';
}
int dfs(int c, int x, int y, int z) {
    if (dp[x][y][z] != -1)
        return dp[x][y][z];
    if (x == sc) {
        return y;
    }
    int limit = 9;
    if (!z)
        limit = vc[x];
    dp[x][y][z] = 0;
    for (int i = 0; i <= limit; i++)
        dp[x][y][z] += dfs(c, x+1, y+(i==1), z ? 1 : i < limit);
    return dp[x][y][z];

}
int countDigitOne(int n) {
    init(n);
    dfs(n, 0, 0,0);
    return dp[0][0][0];
}

int main(void) {
    cout << countDigitOne(13);
    return 0;
}
