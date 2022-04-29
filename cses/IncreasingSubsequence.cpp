//
// Created by wu on 2022/4/26.
//
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    vector<int> dp;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end())
            dp.push_back(num);
        else
            *it = num;
    }
    cout << dp.size();
    return 0;
}
