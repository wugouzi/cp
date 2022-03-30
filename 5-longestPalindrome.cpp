//
// Created by wu on 2022/2/23.
//

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

char vs(string s, int n) {
    if (n % 2) return '#';
    return s[n/2];
}

int main(void) {
    string s = "babad";
    int n = 2 * s.size() - 1;
    int l = 0, r = -1;
    int p[n];
    p[0] = 0;
    string maxs = "";
    for (int i = 0; i < n - 1; i++) {
        p[i] = i >= r ? 0 : min(r - i, p[l+(r-i)]);

        if (i >= r || i + p[l + r - i] >= r) {
            while (i + p[i] <= n - 1 && i - p[i] >= 0 && vs(s, i+p[i]) == vs(s, i-p[i]))
                p[i]++;
            p[i]--;
            int tp = i % 2 ? (p[i] + 1) / 2 * 2 : p[i] / 2 * 2 + 1;
            if (tp > maxs.size()) { maxs = s.substr((i-p[i]+1)/2,tp);}
            l = i - p[i];
            r = i + p[i];
        } else {
            p[i] = p[l + r - i];
        }
    }
    cout << maxs;
    return 0;
}