//
// Created by wu on 2022/3/2.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
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
}

int main(void) {
    vector<int> h={2,1,5,6,2,3};
    cout << largestRectangleArea(h);
}