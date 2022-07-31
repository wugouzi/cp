//
// Created by wu on 2022/3/19.
//

#include "leetcode.h"

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int n = S.size();
    vector<int> xl(n), yl(n), xr(n), yr(n);
    xl[0] = S[0] == 'x';
    yl[0] = S[0] == 'y';
    xr[n-1] = S[n-1] == 'x';
    yr[n-1] = S[n-1] == 'y';
    for (int i = 1; i < n; i++) {
        xl[i] = S[i] == 'x' ? xl[i-1]+1 : xl[i-1];
        yl[i] = S[i] == 'y' ? yl[i-1]+1 : yl[i-1];
        int j = n-i-1;
        xr[j] = S[j] == 'x' ? xr[j+1]+1 : xr[j+1];
        yr[j] = S[j] == 'y' ? yr[j+1]+1 : yr[j+1];
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (xl[i] == yl[i] || yr[i+1] == yr[i+1])
            ans++;
    }
    return ans;
}

int main(void) {
    string s = "ayxbx";
    cout << solution(s);
}