#include "leetcode.h"

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size(), m = nums2.size(), l = 0, r = n, m1, m2;
  while (l <= r) {
    int i = (l+r)/2;
    int j = (m+n)/2 - i;
    int t1 = i == 0 ? INT_MIN : nums1[i-1];
    int t2 = i == n ? INT_MAX : nums1[i];
    int t3 = j == 0 ? INT_MIN : nums2[j-1];
    int t4 = j == m ? INT_MAX : nums2[j];
    if (t1 <= t4) {
      m1 = max(t1, t2);
      m2 = min(t3, t4);
      l = i + 1;
    } else {
      r = i - 1;
    }
  }
  return (m+n)%2 ? m2 : (m1+m2)/2.0;
}


int main(void) {
  vector<int> t1{1,2};
  vector<int> t2{3};
  cout << findMedianSortedArrays(t1, t2);
}
