//
// Created by wu on 2022/4/20.
//

#include <unordered_set>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
using namespace std;
int main(void) {
    int n, tp;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> tp;
        v[i] = tp;
    }
    sort(v.begin(), v.end());
    int ans = 1;
    tp = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] != tp) {
            ans++;
            tp = v[i];
        }
    cout << ans;
    /*int n, tp;
    f >> n;
    unordered_set<int> mp;
    for (int i = 0; i < n; i++) {
        f >> tp;
        mp.insert(tp);
    }
    cout << mp.size() << endl;*/

    return 0;
}