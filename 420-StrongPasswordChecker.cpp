//
// Created by wu on 2022/4/2.
//

#include "leetcode.h"
#define PGSIZE 4
#define PGROUNDUP(sz)  (((sz)+PGSIZE-1) & ~(PGSIZE-1))

int strongPasswordChecker(string password) {
    bool low = false, up = false, dig = false;
    for (auto& c : password) {
        if (isdigit(c))
            dig = true;
        if ('a' <= c && c <= 'z')
            low = true;
        if ('A' <= c && c <= 'Z')
            up = true;
        if (low && up && dig)
            break;
    }
    int type = low+up+dig;
    int n = password.size();
    if (n < 6) {
        char ch = '#';
        int cnt = 0, res = 0, mcnt=0;
        for (auto& c : password) {
            if (ch == c)
                cnt++;
            else {
                ch = c;
                if (cnt>mcnt) mcnt = cnt;
                cnt = 1;
            }
        }
        if (mcnt <= 4) return 6-n;
        return 2;
    } else if (n >= 6 && n <= 20) {
        char ch = '#';
        int cnt = 0, ans = 0;
        for (auto& c : password) {
            if (ch == c)
                cnt++;
            else {
                if (cnt) ans += cnt/3;
                cnt = 1;
                ch = c;
            }
        }
        ans += cnt/3;
        return max(ans, 3-type);
    } else {
        vector<int> cnts(3);
        int cnt = 0, tot = 0;
        char ch = '#';
        for (auto& c : password) {
            if (ch == c) cnt++;
            else {
                if (cnt>= 3) {
                    cnts[cnt%3]++;
                }
                tot += cnt/3;
                cnt = 1;
                ch = c;
            }
        }
        tot += cnt/3;
        if (cnt) cnts[cnt%3]++;
        int base = n-20, cur = base;
        for (int i = 0; i < 3; i++) {
            if (i == 2) cnts[i] = tot;
            if (cnts[i] && cur) {
                int b = min(cur, cnts[i] * (i + 1));
                cur -= b, tot -= b / (i + 1);
            }
        }
        return base+max(tot, 3-type);
    }
}

int main(void) {
    for (int i = 1; i < 100; i++)
        cout << PGROUNDUP(i) << ' ';
}