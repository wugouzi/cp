//
// Created by wu on 2022/5/22.
//

#include "leetcode.h"

vector<int> mp;
int limit, total;
//1 win 0 lose
int dfs(int mask, int cnt) {
    if (mp[mask] != -1)
        return mp[mask];
    for (int i = 0; i < limit; i++) {
        if (((mask >> i) & 1) == 0) {
            if (cnt + i + 1 >= total || !dfs(mask | (1 << i), cnt + i + 1)) {
                mp[mask] = 1;
                return 1;
            }
        }
    }
    mp[mask] = 0;
    return 0;
}
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    limit = maxChoosableInteger;
    total = desiredTotal;
    if ((maxChoosableInteger+1)*maxChoosableInteger/2< desiredTotal)
        return 0;
    mp.resize((1<<maxChoosableInteger)-1,-1);
    dfs(0,0);
    return mp[0];
}
/*
unordered_map<int, bool> memo;
bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal) {
    if (!memo.count(usedNumbers)) {
        bool res = false;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (((usedNumbers >> i) & 1) == 0) {
                if (i + currentTotal >= desiredTotal) {
                    res = true;
                    break;
                }
                if (!dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i)) {
                    res = true;
                    break;
                }
            }
        }
        memo[usedNumbers] = res;
    } else {
        return memo[usedNumbers];
    }
    cout << usedNumbers << ' ' << currentTotal << ' ' << memo[usedNumbers] << endl;
    return memo[usedNumbers];
}
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {
        return false;
    }
    return dfs(maxChoosableInteger, 0, desiredTotal, 0);
}*/



int main(void) {
    cout << 0+canIWin(10,40);
}