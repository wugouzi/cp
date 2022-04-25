//
// Created by wu on 2022/4/24.
//

#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    int n, sum=0;
    cin >> n;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        sum += coin[i];
    }
    //vector<vector<int>> dp(n, vector<int>(sum+1));
    vector<int> dp(sum+1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = sum; j >= coin[i]; j--)
            dp[j] |= dp[j-coin[i]];
    vector<int> ans;
    for (int i = 1; i <= sum; i++)
        if (dp[i])
            ans.push_back(i);
    int m = ans.size();
    cout << m << endl;
    for (int i = 0; i < m-1; i++)
        cout << ans[i] << ' ';
    cout << ans[m-1];
}