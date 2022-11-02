//
// Created by wu on 2022/10/18.
//

#include "leetcode.h"

int atMostNGivenDigitSet(vector<string>& _digits, int n) {
    vector<int> digits;
    for (auto &s : _digits)
        digits.push_back(s[0]-'0');
    vector<int> d;
    while (n) {
        d.push_back(n % 10);
        n /= 10;
    }
    int dn = d.size(), m = digits.size();
    int k = 0;
    vector<int> bound(10);
    vector<bool> mp(10);
    for (auto &n : digits)
        mp[n] = true;
    int i, j;
    for (j = 0, i = 0; i < m && j < 10; i++) {
        while (j <= digits[i])
            bound[j++] = i;
    }
    while (j < 10) {
        bound[j++] = m;
    }

    int d0 = bound[d[dn-1]], d1 = mp[d[dn-1]];
    for (int i = dn-2; i >= 0; i--) {
        d0 = m + m*d0 + d1*bound[d[i]];
        d1 &= mp[d[i]];
    }
    return d0+d1;
}

int main(void) {
    vector<string> s{"7"};
    int n = 8;
    cout << atMostNGivenDigitSet(s,n);
}
