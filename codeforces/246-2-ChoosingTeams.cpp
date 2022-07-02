//
// Created by wu on 2022/6/1.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int pl[3000];
int main(void) {
    int n, m,tp;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> tp;
        if (tp+m<=5)
            ans++;
    }

    cout << ans/3;
    return 0;
}