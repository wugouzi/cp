//
// Created by wu on 2022/4/10.
//

#include "leetcode.h"
int n1, n2;
bool compare(vector<int> nums1, int i, vector<int> nums2, int j) {
    for (int k = 0; i + k < nums1.size() && j + k < nums2.size(); k++) {
        if (nums1[i + k] < nums2[j + k])
            return true;
        else if (nums1[i + k] > nums2[j + k])
            return false;
    }
    if (nums1.size()-i < nums2.size()-j)
        return true;
    return false;
}
vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> tmp(n1+n2);
    int pos = 0, i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (compare(nums1, i, nums2, j))
            tmp[pos++] = nums2[j++];
        else
            tmp[pos++] = nums1[i++];
    }
    while (i < n1)
        tmp[pos++] = nums1[i++];
    while (j < n2)
        tmp[pos++] = nums2[j++];
    return tmp;
}
vector<int> getk(vector<int>& nums1, int k) {
    vector<int> ans;
    if (k >= nums1.size()) return ans;
    int i, cnt = 0;
    for (i = 0; i < nums1.size(); i++) {
        while (!ans.empty() && cnt < k && ans.back() < nums1[i]) {
            ans.pop_back();
            cnt++;
        }
        ans.push_back(nums1[i]);
    }
    ans.resize(ans.size()-k+cnt);
    return ans;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    n1 = nums1.size(), n2 = nums2.size();
    int drop = n1+n2-k;
    vector<int> ans(k,0);

    for (int i = max(drop-n2,0); i <= min(n1, drop); i++) {
        vector<int> tp1 = getk(nums1, i);
        vector<int> tp2 = getk(nums2, drop-i);
        ans = max(merge(tp1, tp2), ans);
        if (ans.size() != k)
            cout << i << endl;
    }
    return ans;
}

int main(void) {
    vector<int> nums1 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<int> nums2 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int k = 100;
    vector<int> tp = maxNumber(nums1, nums2, k);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}