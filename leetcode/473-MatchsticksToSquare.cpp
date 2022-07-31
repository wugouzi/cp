//
// Created by wu on 2022/6/1.
//

#include "leetcode.h"

bool makesquare(vector<int>& matchsticks) {
    int sum = 0;
    for (auto& d : matchsticks)
        sum += d;
    if (sum % 4)
        return false;
    sum /= 4;
    int n = matchsticks.size();
    vector<pair<int,int>> best(1<<n,{n,sum+1});
    best[0] = make_pair(0,0);
    for (int i = 1; i < 1<<n; i++)
        for (int j = 0; j < n; j++)
            if (i&(1<<j)) {
                auto op = best[i^(1<<j)];
                if (op.second+matchsticks[j] <= sum)
                    op.second += matchsticks[j];
                else {
                    op.second = matchsticks[j];
                    op.first++;
                }
                best[i] = min(best[i],op);
            }
    int m = (1<<n)-1;
    cout << best[m].first << ' ' << best[m].second<<endl;
    if (best[m].first == 3 && best[m].second == sum)
        return true;
    return false;
}

int main(void) {
    vector<int> t = {1,1,2,2,2};
    cout << 0+ makesquare(t);
}