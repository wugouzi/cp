//
// Created by wu on 2022/3/2.
//
#include "leetcode.h"

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> l(n, -1), r(n, n);
    stack<int> st1, st2;
    for (int i = 0; i < n; i++) {
        while (!st1.empty() && heights[i] < heights[st1.top()]) {
            r[st1.top()] = i;
            st1.pop();
        }
        st1.push(i);
        int j = n-i-1;
        while (!st2.empty() && heights[j] < heights[st2.top()]) {
            l[st2.top()] = j;
            st2.pop();
        }
        st2.push(j);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (r[i] - l[i] - 1) *);
    }
    return ans;
}
/*
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n, n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            right[s.top()] = i;
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    int lmax = 0;
    for (int i = 0; i < n; i++) lmax = max(lmax, heights[i] * (right[i] - left[i] - 1));
    return lmax;
}*/

int main(void) {
    vector<int> h={2,1,5,6,2,3};
    cout << largestRectangleArea(h);
}