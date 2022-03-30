//
// Created by wu on 2022/2/28.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    if (!(m * n)) return m + n;
    vector<vector<int>> tp(n+1, vector<int>(m+1));
    for (int i = 0; i < n + 1; i++) tp[i][0] = i;
    for (int i = 0; i < m + 1; i++) tp[0][i] = i;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            tp[i][j] = min(tp[i - 1][j] + 1, tp[i][j - 1] + 1);
            tp[i][j] = min(tp[i][j],
                           word1[i] == word2[j] ? tp[i - 1][j - 1] : tp[i-1][j-1]+1);
        }
    }
    return tp[n][m];
}

int main(void) {
    cout << minDistance("horse", "ros");
}