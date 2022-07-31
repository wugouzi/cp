//
// Created by wu on 2022/6/9.
//

#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> recs;
    int n;
    vector<int> areas;
    Solution(vector<vector<int>>& rects) {
        recs = rects;
        n = recs.size();
        areas.resize(n+1);
        for (int i = 1; i <= n; i++) {
            areas[i] = areas[i-1]+(rects[i-1][2]-rects[i-1][0]+1)*(rects[i-1][3]-rects[i-1][1]+1);
        }
    }

    vector<int> pick() {
        int t1 = rand()%areas[n];
        int l = upper_bound(areas.begin(),areas.end(),t1)-areas.begin()-1;
        int len = (recs[l][2]-recs[l][0]+1);
        int hgt = recs[l][3] - recs[l][1]+1;
        if (l > 0)
            t1 -= areas[l-1];
        return {recs[l][0]+t1%len,recs[l][1]+t1/len};

    }
};
int main(void) {
    vector<vector<int>> tp = {{-2, -2, 1, 1}, {2, 2, 4, 6}};
    Solution solution(tp);
    solution.pick(); // return [1, -2]
    solution.pick(); // return [1, -1]
    solution.pick(); // return [-1, -2]
    solution.pick(); // return [-2, -2]
    solution.pick(); // return [0, 0]

}