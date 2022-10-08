//
// Created by wu on 2022/10/2.
//

#include "leetcode.h"

int minimizeXor(int num1, int num2) {
    int n = __builtin_popcount(num2);
    int m = __builtin_popcount(num1);
    long long x = 0;
    if (n > m) {
        int r = m-n;
        x = num1;
        for (int i = 0;i < 32; i++) {
            if (!((1 << i) & num1)) {
                x |= 1 << i;
                r--;
            }
            if (r == 0)
                return x;
        }
    } else {
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & num1) {
                x |= 1 << i;
                n--;
                if (n == 0)
                    return x;
            }
        }
    }
    return x;
}

int main(void) {
    cout << minimizeXor(1, 12);
}