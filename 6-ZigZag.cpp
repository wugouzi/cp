//
// Created by wu on 2022/2/24.
//

#include<iostream>
#include<string>
using namespace  std;

string convert(string s, int numRows) {
    int n = s.size();
    if (n <= numRows || numRows <= 2) return s;
    string ps (n, '0');
    int mod = 2 * numRows - 2;
    int j = 0;
    for (int i = 0; i < n; i += mod) ps[j++] = s[i];
    for (int r = 1; r < numRows - 1; r++) {
        int i = r;
        bool f = true;
        while (i < n) {
            ps[j++] = s[i];
            if (f) {
                i += mod - 2 * r;
                f = false;
            }
            else {
                i += 2 * r;
                f = true;
            }
        }
    }
    for (int i = numRows - 1; i < n; i += mod) ps[j++] = s[i];

    return ps;
}

int main() {
    string s = "AB";
    int numRows = 1;
    cout << convert(s, numRows);
}