//
// Created by wu on 2022/4/7.
//

#include "leetcode.h"

int strStr(string haystack, string needle) {
    int n = needle.size(), m = haystack.size();
    if (n > m) return -1;
    vector<int> overlap(n);
    overlap[0] = -1;
    for (int i = 1; i < n; i++) {
        overlap[i] = overlap[i-1]+1;
        while (overlap[i] > 0 && needle[i-1] != needle[overlap[i]-1])
            overlap[i] = overlap[overlap[i]-1]+1;
    }
    int i = 0, j;
    while (i < m) {
        for (j = 0; i+j < m && haystack[i+j] == needle[j]; j++);
        if (j == n) return i;
        if (j > 0) i += max(1, j-overlap[j-1]-1);
        else i++;
    }
    return -1;
}

int main(void) {
    string haystack = "hello", needle = "ll";
    cout << strStr(haystack, needle);
}