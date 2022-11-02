//
// Created by wu on 2022/10/16.
//
#include "leetcode.h"
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    vector<int> mins, maxs, minl, minr, maxl, maxr;
    int ll = -1, lg = -1, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] < minK) {
            ll = i;
            if (minr.size() < minl.size())
                minr.push_back(i);
        }
        if (nums[i] > maxK) {
            lg = i;
            if (maxr.size() < maxl.size())
                maxr.push_back(i);
        }
        if (nums[i] == minK) {
            minl.push_back(ll);
            mins.push_back(i);
        }
        if (nums[i] == maxK) {
            maxl.push_back(lg);
            maxs.push_back(i);
        }
    }
    while (minr.size() < minl.size())
        minr.push_back(n);
    while (maxr.size() < maxl.size())
        maxr.push_back(n);
    int i = 0, j = 0, n1 = mins.size(), n2 = maxs.size();
    long long ans = 0;
    auto check = [&](int i, int j) {
        if (mins[i] >= maxr[j] || maxs[j] <= minl[i])
            return 1;
        else if (maxs[j] >= minr[i] || mins[i] <= maxl[j])
            return 2;
        return 0;
    };
    while (i < n1 && j < n2) {
        if (check(i, j) == 1)
            j++;
        else if (check(i, j) == 2)
            i++;
        else {
            int tp = j;
            while (tp < n2 && check(i, tp) == 0) {
                long long d1 = min(mins[i], maxs[tp]) - max(minl[i], maxl[tp]);
                long long d2 = min(minr[i], maxr[tp]) - max(mins[i], maxs[tp]);
                ans += d1 * d2;
                tp = min(minr[i], maxr[tp]);
            }
            i++;
        }
    }
    return ans;
}

int main(void) {
    //vector<int> n{1,3,5,2,7,5};int mink = 1;int maxk = 5;
    //vector<int> n{1,1,1,1};int mink = 1;int maxk = 1;
    vector<int> n{35054,398719,945315,945315,820417,945315,35054,945315,171832,945315,35054,109750,790964,441974,552913};int mink=35054;int maxk=945315;
    cout << countSubarrays(n, mink, maxk);
}