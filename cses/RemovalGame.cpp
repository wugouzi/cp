//
// Created by wu on 2022/4/24.
//

#include <iostream>
#include <vector>
#include <deque>
//https://medium.com/intellectually-yours/cses-removal-game-d1a0c2753d8d
//https://codeforces.com/blog/entry/70018
using namespace std;

int main(void) {
    int n;
    cin >> n;
    /*vector<vector<pair<long long,long long>>> dp(n, vector<pair<long long, long long>>(n));
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    for (int i = 0; i < n; i++)
            dp[i][i] = make_pair(coin[i], 0);
    int l = 1;
    while (l < n) {
        for (int i = 0; i + l < n; i++) {
            int j = i+l;
            if (dp[i+1][j].second+coin[i] >= dp[i][j-1].second+coin[j]) {
                dp[i][j].first = dp[i+1][j].second+coin[i];
                dp[i][j].second = dp[i+1][j].first;
            } else {
                dp[i][j].first = dp[i][j-1].second+coin[j];
                dp[i][j].second = dp[i][j-1].first;
            }
        }
        l++;
    }
    cout << dp[0][n-1].first;*/
    long long sum = 0;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = c[i];
    for (int l = 1; l < n; l++) {
        for (int i = 0; i+l < n; i++)
            dp[i][i+l] = max(c[i]-dp[i+1][i+l], c[i+l]-dp[i][i+l-1]);
    }
    cout << (sum+dp[0][n-1])/2;
    return 0;
}