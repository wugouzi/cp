//
// Created by wu on 2022/4/7.
//

#include "leetcode.h"

bool rotateString(string s, string goal) {
    if (s.size() != goal.size())
        return false;
    int n = s.size();
    vector<int> overlap(n);
    overlap[0] = -1;
    for (int i = 1; i < n; i++) {
        overlap[i] = overlap[i-1]+1;
        while (overlap[i] > 0 && goal[i-1] != goal[overlap[i]-1]) {
            overlap[i] = overlap[overlap[i]-1]+1;
        }
    }
    s = s + s;
    int m = n<<1;
    int j;
    for (int i = 0; i < n;) {
        for (j = 0; i+j<m && s[i+j] == goal[j]; j++);
        if (j == n) return true;
        i += max(1, j-overlap[j-1]-1);
    }
    return false;
}

int main(void) {
    string s = "nnnnnn", goal = "nnnnnn";
    cout << 1+ rotateString(s, goal);
}