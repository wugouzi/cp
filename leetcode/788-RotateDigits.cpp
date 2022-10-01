//
// Created by wu on 2022/9/25.
//

#include "leetcode.h"

int dp[10][2][2];
vector<int> dig, dd{0,1,2,5,6,8,9};
bool diff(int k) {
    return k == 2 || k == 5 || k == 6 || k == 9;
}
int f(int d, bool bound, bool dif) {
    if (d == dig.size())
        return dif;
    if (dp[d][bound][dif] != -1)
        return dp[d][bound][dif];
    int ans = 0;
    for (int i = 0; i < dd.size(); i++) {
        if (bound && dd[i] > dig[d])
            break;
        ans += f(d+1, bound && dd[i] == dig[d], diff(dd[i]));
    }
    dp[d][bound][dif] = ans;
    return ans;
}
int rotatedDigits(int d) {
    memset(dp, -1, sizeof(dp));
    int k = d;
    while (k) {
        dig.push_back(k%10);
        k /= 10;
    }
    reverse(dig.begin(), dig.end());
    return f(0, true, false);
}

int main(void) {
    cout << rotatedDigits(2);
}