//
// Created by wu on 2022/5/20.
//

#include "leetcode.h"

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<vector<int>> tp;
    tp = intervals;
    int n = intervals.size();
    for (int i = 0; i < n; i++)
        tp[i].push_back(i);
    sort(tp.begin(), tp.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while (l < r) {
            int med = (l+r)/2;
            if (tp[med][0] < intervals[i][0])
                l = med+1;
            else if (tp[med][0] > intervals[i][0])
                r = med-1;
            else {
                l = med;
                break;
            }
        }
        l++, r = n-1;
        while (l < r) {
            int med = (l+r)/2;
            if (tp[med][0] >= intervals[i][1])
                r = med;
            else if (tp[med][0] < intervals[i][1])
                l = med+1;
        }
        ans[i] = l < n && tp[l][0] >= intervals[i][1]? tp[l][2] : -1;
    }
    return ans;
}

int main(void) {
    vector<vector<int>> inte = {{1,4},{2,3},{3,4}};
    vector<int> tp = findRightInterval(inte);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}