//
// Created by wu on 2022/4/22.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> c;
int main(void) {
    int n, b, N=1e9+7;
    //fstream f("../cses/test_input.txt");
    cin >> n >> b;

    vector<vector<long long>> dp(n, vector<long long>(b+1));
    int cur;
    cin >> cur;
    if (cur == 0)
        for (int i = 1; i <= b; i++)
            dp[0][i] = 1;
    else
        dp[0][cur] = 1;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        if (cur)
            for (int k : {cur-1,cur,cur+1}) {
                if (k >= 1 && k <= b)
                    dp[i][cur] += dp[i - 1][k];
                dp[i][cur] %= N;
            }
        else {
            for (int j = 1; j <= b; j++)
                for (int k : {j-1, j, j+1}) {
                    if (k >= 1 && k <= b)
                        dp[i][j] += dp[i-1][k];
                    dp[i][j] %= N;
                }
        }
    }
    long long ans=0;
    if (cur)
        ans = dp[n-1][cur];
    else
        for (int i = 1; i <= b; i++)
            ans += dp[n-1][i];
    cout << ans%N;
    return 0;

}