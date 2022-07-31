//
// Created by wu on 2022/3/27.
//

#include "leetcode.h"

long long kth(int k, int len, bool f) {
    long long ans = 0;
    if (len <= 2 && k > 9) return -1;
    if (len == 1)
        return k;
    if (len == 2)
        return k * 11;
    int p = pow(10, (len-1)/2);
    int kq, kp;
    if (f) {
        kq = (k - 1) / p + 1;
        if (kq >= 10) return -1;
        kp = (k-1) % p;
    }
    else {
        kq = k/p;
        if (kq > 9) return -1;
        kp = k % p;
    }

    return kq * pow(10, len-1) + 10 * kth(kp, len-2,false)+kq;
}
vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    vector<long long> ans;
    for (auto& q : queries) {
        ans.push_back(kth(q, intLength,true));
    }
    return ans;
}

int main(void) {
    vector<int> tp = {696771750,62,47,14,17,192356691,209793716,23,220935614,447911113,5,4,72};
    int l = 4;
    vector<long long> tpp = kthPalindrome(tp, l);
    for (int i = 0; i < tpp.size(); i++) cout << tpp[i] << ' ';
}