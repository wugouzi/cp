//
// Created by wu on 2022/9/28.
//

#include "leetcode.h"

int StoredEnergy(int storeLimit, const vector<int>& power, const vector<vector<int>>& supply)
{
    int ans = 0;
    for (int i = 1, j = 0; i < supply.size() + 1 && j < power.size(); i++) {
        while (j < power.size() && (i == supply.size() || j < supply[i][0])) {
            int delta = 0;
            if (power[j] > supply[i-1][2])
                delta = power[j] - supply[i-1][2];
            if (power[j] < supply[i-1][1])
                delta = power[j] - supply[i-1][1];
            ans = min(storeLimit, max(0, ans + delta));
            j++;
        }
    }
    return ans;
}

int main(void) {
    int k = 10;
    vector<int> p{1,3,4,3,6};
    vector<vector<int>> s{{0,2,3}};
    cout << StoredEnergy(k, p, s);
}