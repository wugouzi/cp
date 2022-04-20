//
// Created by wu on 2022/4/20.
//

#include <unordered_set>
#include <iostream>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    unordered_set<int> mp;
    int tp;
    for (int i = 0; i < n; i++) {
        cin >> tp;
        mp.insert(tp);
    }
    cout << mp.size();
    return 0;
}