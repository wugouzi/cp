#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int findk(vector<int> nums1, int i, vector<int> nums2, int j, int k) {
    if (i >= nums1.size()) return nums2[j + k - 1];
    if (j >= nums2.size()) return nums1[i + k - 1];

    if (k == 1) return fmin(nums1[i],nums2[j]);

    int val1 = nums1.size() >= i + k/2 ? nums1[i + k/2 - 1] : numeric_limits<int>::max();
    int val2 = nums2.size() >= j + k/2 ? nums2[j + k/2 - 1] : numeric_limits<int>::max();
    if (val1 >= val2)
        return findk(nums1, i, nums2, j+k/2,k - k/2);
    else
        return findk(nums1, i+k/2,nums2,j,k-k/2);
}

int main() {
    vector<int> nums1 = {1,2}, nums2 = {3,4};

    int m = nums1.size(), n = nums2.size();
    int l = 0, r = m;
    int m1 = 0, m2 = 0;
    while (l <= r) {
        int i = (l + r) / 2;
        int j = (m + n + 1) / 2 - i;

        int li = i == 0 ? INT_MIN : nums1[i-1];
        int ri = i == m ? INT_MAX : nums1[i];
        int lj = j == 0 ? INT_MIN : nums2[j-1];
        int rj = j == n ? INT_MAX : nums2[j];

        if (li <= rj) {
            m1 = fmax(li,lj);
            m2 = fmin(ri,rj);
            l = i + 1;
        }
        else {
            r = i - 1;
        }
    }
    double res =  (m+n) % 2 ? m1 : (m1 + m2) / 2.0;
    cout<<res;
    /*
    while (left <= right) {
        // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
        // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
        int nums_im1 = (i == 0 ? Integer.MIN_VALUE : nums1[i - 1]);
        int nums_i = (i == m ? Integer.MAX_VALUE : nums1[i]);
        int nums_jm1 = (j == 0 ? Integer.MIN_VALUE : nums2[j - 1]);
        int nums_j = (j == n ? Integer.MAX_VALUE : nums2[j]);

        if (nums_im1 <= nums_j) {
            median1 = Math.max(nums_im1, nums_jm1);
            median2 = Math.min(nums_i, nums_j);
            left = i + 1;
        } else {
            right = i - 1;
        }
    }*/

    return 0;
}
