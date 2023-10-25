//
// Created by wu on 2023/10/18.
//

#include "leetcode.h"

int maxProfit(int k, vector<int>& prices) {
  int dp[6][3][2];
  memset(dp, 0, sizeof(dp));
  int n = prices.size();
  for (int i = 0; i <= k; i++) {
    dp[0][i][0] = dp[0][i][1] = INT_MIN / 2;
  }
  dp[0][1][0] = -prices[0];
  dp[0][0][1] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] + prices[i]);
      dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] - prices[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "(" << dp[i][j][0] << ", " << dp[i][j][1] << ") ";
    }
    cout << endl;
  }
  for (int i = 1; i <= k; i++)
    ans = max(dp[n-1][i][1], ans);
  return ans;
}

int main(void) {
  int k = 2;
  vector<int> prices{3,2,6,5,0,3};
  cout << maxProfit(k, prices);
}