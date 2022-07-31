//
// Created by wu on 2022/7/1.
//

#include "leetcode.h"

vector<int> nums;
unordered_set<int> dp[20][20];
void dfs(int l, int r) {
    if (dp[l][r].size() > 0)
        return;
    if (l == r) {
        dp[l][l].insert(nums[l]);
        return;
    }
    for (int i = l+1; i < r; i++) {
        if (nums[i] >= 0) continue;
        dfs(l,i-1);
        dfs(i+1,r);
        for (auto& t1 : dp[l][i-1])
            for (auto& t2 : dp[i+1][r])
                if (nums[i] == -1)
                    dp[l][r].emplace(t1+t2);
                else if (nums[i] == -2)
                    dp[l][r].emplace(t1-t2);
                else if (nums[i] == -3)
                    dp[l][r].emplace(t1*t2);
    }
}
vector<int> diffWaysToCompute(string expression) {
    bool last_digit = false;

    int tp = 0;
    for (auto c : expression) {
        if (isdigit(c)) {
            if (last_digit)
                tp = tp*10+c-'0';
            else {
                tp = c-'0';
                last_digit = true;
            }
        } else {
            if (last_digit) {
                nums.push_back(tp);
                last_digit = false;
            }
            if (c == '+')
                nums.push_back(-1);
            else if (c == '-')
                nums.push_back(-2);
            else if (c == '*')
                nums.push_back(-3);
        }
    }
    nums.push_back(tp);
    vector<int> ans;
    int n = nums.size();
    dfs(0,n-1);
    for (auto& t : dp[0][n-1]) {
        ans.push_back(t);
    }
    return ans;
}

int main(void) {
    string s = "2-1-1";
    vector<int> tp = diffWaysToCompute(s);
    for (auto& c : tp) cout << c << ' ';
}