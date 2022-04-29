//
// Created by wu on 2022/4/26.
//
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n,N=1e9+7;
    cin >> n;
    int sum = (1+n)*n/2;
    if (sum%2) {
        cout << 0;
        return 0;
    }
    sum/=2;
    /*vector<vector<long long>> dp(sum+1, vector<long long>(n));
    dp[0][0] = 1;
    for (int j = 1; j < n; j++)
        for (int i = 0; i <= sum; i++)
            if (i < j)
                dp[i][j] = dp[i][j-1];
            else
                dp[i][j] = (dp[i][j-1]+dp[i-j][j-1])%N;
    cout << dp[sum][n-1];*/
    vector<long long> dp(sum+1);
    dp[0] = 1;
    //always put n in the second part
    for (int j = 1; j < n; j++)
        for (int i = sum; i >= j; i--)
            dp[i] = (dp[i] + dp[i-j])%N;
    cout << dp[sum];
    return 0;
}
