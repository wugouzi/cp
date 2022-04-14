//
// Created by wu on 2022/4/12.
//

#include "leetcode.h"

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    using Pair = pair<int, int>;
    int n = position.size();
    if (n==1) return 1;
    vector<Pair> cars(n);
    for (int i = 0; i < n; i++)
        cars[i] = make_pair(position[i], speed[i]);
    sort(cars.begin(), cars.end(), [](const Pair& s1, const Pair& s2)->bool {
        return s1.first < s2.first;
    });
    int ans=0,i=n-1;
    while (i >= 0) {
        int j = i-1;
        while (j >= 0 && cars[j].second > cars[i].second &&
        cars[j].first+(cars[i].first-cars[j].first)/(double)(cars[j].second-cars[i].second)*cars[j].second <= target)
            j--;
        i = j;
        ans++;
    }
    return ans;
}

int main(void) {
    int t = 10;
    vector<int> p = {0,4,2}, s = {2,1,3};
    cout << carFleet(t, p, s);
}