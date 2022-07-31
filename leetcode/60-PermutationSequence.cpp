//
// Created by wu on 2022/3/24.
//

#include "leetcode.h"

string getPermutation(int n, int k) {
    vector<bool> used(n);
    string s(n, ' ');
    int fac = 1;
    for (int i = n; i > 1; i--) fac *= i;
    for (int i = 0; i < n; i++) {
        fac /= (n-i);
        int ith = (k-1) / fac + 1;
        k -= ((k-1)/fac) * fac;
        int p = 0;
        for (int j = 0; j < ith; p++)
            if (!used[p])
                j++;
        used[p-1] = true;
        s[i] = p+'0';
    }
    return s;
}

int main(void) {
    cout << getPermutation(4, 9);
}