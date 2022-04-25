//
// Created by wu on 2022/4/24.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1));
    for (int i = 0; i <= n1; i++)
        dp[i][0] = i;
    for (int i = 0; i <= n2; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++) {
            dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,
                                            s1[i-1] == s2[j-1] ? dp[i-1][j-1] : dp[i-1][j-1]+1));
        }
    cout << dp[n1][n2];
    return 0;
}