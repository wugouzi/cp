//
// Created by wu on 2022/3/23.
//

#include "leetcode.h"

int steps(int n, int cur) {
    int l = cur, r = cur;
    int cnt = 0;
    while (l <= n) {
        cnt += min(n, r) - l + 1;
        l *= 10;
        r = r * 10 + 9;
    }
    return cnt;
}
int findKthNumber(int n, int k) {
    int i = 1;
    while (k) {
        if (k == 1)
        int tp = steps(n, i);
        if (tp < k) {
            i++;
            k -= tp;
        } else {
            i *= 10;
            k--;
        }
        //cout << i << endl;
    }
    return i;
}

int main(void) {
    cout << findKthNumber(13,2);
}