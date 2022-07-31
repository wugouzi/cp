//
// Created by wu on 2022/2/25.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;



bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();

    auto match = [&] (int i, int j) {
        if ((!i && j) || (i && !j)) return false;
        if (p[j - 1] == '.') return true;
        return s[i - 1] == p[j - 1];
    };
    vector<vector<int>> f(n+1,vector<int>(m+1));
    f[0][0] = true;
    for (int j = 1; j <= m; j++) f[0][j] = false;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*') {
                f[i][j] = f[i][j - 2];
                if (match(i,j-1)) f[i][j] |= f[i-1][j];
            } else {
                if (match(i,j)) {
                    f[i][j] = f[i-1][j-1];
                } else {
                    f[i][j] = false;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j ++) cout << f[i][j] <<' ';
        cout<<endl;
    }
    return f[n][m];
}

int main(void) {
    string s = "aaa";
    string p = "aa";
    cout << isMatch(s,p);
}
