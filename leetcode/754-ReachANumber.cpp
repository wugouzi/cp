//
// Created by wu on 2022/11/4.
//

#include "leetcode.h"

int reachNumber(int target) {
    target = abs(target);
    int sum = 0;
    int l = 1, r = target;
    while (l < r) {
        int mid = (l+r)/2;
        int val = (1+mid)*mid/2;
        if (val >= target) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    int val = (l+1)*l/2;
    if ((val-target)%2 != 0) {
        val += l + 1;
        l++;
        if ((val-target)%2 != 0) {
            l++;
        }
    }
    return l;
}

int main(void) {
    cout << reachNumber(5);
}