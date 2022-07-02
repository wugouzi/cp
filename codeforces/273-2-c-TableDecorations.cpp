//
// Created by wu on 2022/6/1.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<long long> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(),a.end());
    if (a[2]/2>=a[0]+a[1]) cout << a[0]+a[1];
    else cout << (a[0]+a[1]+a[2])/3;
    return 0;
}