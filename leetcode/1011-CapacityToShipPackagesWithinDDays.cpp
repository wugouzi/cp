//
// Created by wu on 2023/3/25.
//

#include "leetcode.h"

int shipWithinDays(vector<int>& weights, int days) {
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int l = sum / days, r = sum, n = weights.size();
    while (l < r) {
        int mid = (l + r) / 2;
        bool f = true;
        for (int i = 0, j = 1, rem = mid; i < n; i++) {
            if (weights[i] > mid) {
                f = false;
                break;
            }
            if (rem >= weights[i])
                rem -= weights[i];
            else {
                j++;
                if (j > days) {
                    f = false;
                    break;
                }
                rem = mid - weights[i];
            }
        }
        if (f) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main(void) {
    vector<int> t{1,2,3,4,5,6,7,8,9,10};
    int d = 5;
    cout << shipWithinDays(t, d);
}
