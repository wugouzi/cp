//
// Created by wu on 2022/9/28.
//

#include "leetcode.h"

int dp[110][110][110];
int dfs(vector<int>& boxes, int l, int r, int k) {
    if (l > r) return 0;
    if (l == r)
        return (k+1)*(k+1);
    if (dp[l][r][k] != 0)
        return dp[l][r][k];
    while (l + 1 <= r && boxes[l] == boxes[l+1]) {
        l++;
        k++;
    }
    int ans = dfs(boxes, l+1, r, 0) + (k+1)*(k+1);
    for (int j = l + 1; j <= r; j++)
        if (boxes[l] == boxes[j]) {
            ans = max(ans, dfs(boxes, j, r, k+1) + dfs(boxes, l+1, j-1, 0));
        }
    dp[l][r][k] = ans;
    cout << l << ' ' << r << ' ' << k << ' ' << ans << endl;
    return ans;
}
int removeBoxes(vector<int>& boxes) {
    memset(dp, 0, sizeof(dp));
    return dfs(boxes, 0, boxes.size()-1, 0);
}

int main(void) {
    vector<int> b{1,2,2,1,1,1,2,1,1,2,1,2,1,1,2,2,1,1,2,2,1,1,1,2,2,2,2,1,2,1,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,1,1,2,2,1,2,1,2,2,1,2,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,2,1,2,2,1};
    cout << removeBoxes(b);
}