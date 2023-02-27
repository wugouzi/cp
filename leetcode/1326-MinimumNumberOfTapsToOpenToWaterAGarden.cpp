//
// Created by wu on 2023/2/21.
//

#include "leetcode.h"

int minTaps(int n, vector<int>& ranges) {
    vector<vector<int>> pp;
    for (int i = 0; i < ranges.size(); i++) {
        pp.push_back({max(0,i-ranges[i]),min(n, i+ranges[i])});
    }
    sort(pp.begin(), pp.end());
    int r = 0, rr = 0, ans = 1;
    int i = 0;
    for (; i < pp.size(); i++) {
        if (pp[i][0] == 0) {
            r = max(r, pp[i][1]);
        } else {
            break;
        }
    }
    if (r >= n) return 1;
    for (; i < pp.size(); i++) {
        if (pp[i][0] <= r) {
            rr = max(rr, pp[i][1]);
            if (rr >= n)
                return ans;
        } else if (rr >= pp[i][0]) {
            ans++;
            r = rr;
        } else {
            return -1;
        }
    }

    if (r >= n)
        return ans;
    return -1;
}

int main(void) {
    // int n = 7;
    // vector<int> r = {1,2,1,0,2,1,0,1};
    int n = 97;
    vector<int> r = {1,5,3,1,4,5,5,1,2,0,2,2,4,3,0,0,1,4,5,5,0,3,5,1,1,0,0,0,4,1,1,1,0,4,4,1,0,0,2,5,5,4,4,4,2,4,3,4,4,2,3,4,0,2,0,1,0,4,2,3,0,0,0,1,5,2,0,2,4,4,3,3,0,0,3,1,1,1,4,2,5,2,3,1,0,1,0,2,4,3,4,0,2,4,1,1,2,5};
    cout << minTaps(n, r);
}