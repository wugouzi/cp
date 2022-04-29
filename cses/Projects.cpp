//
// Created by wu on 2022/4/26.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n);
    map<int,int> compress;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        compress[a[i]], compress[b[i]];
    }
    int coord = 0;
    for (auto&[_,c] : compress)
        c = coord++;
    vector<long long> dp(coord);
    vector<vector<pair<int,long long>>> projects(coord);
    for (int i = 0; i < n; i++)
        projects[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
    for (int i = 0; i < coord; i++) {
        if (i > 0)
            dp[i] = dp[i-1];
        for (auto& c : projects[i])
            if (c.first == 0)
                dp[i] = max(dp[i], c.second);
            else
                dp[i] = max(dp[i], c.second+dp[c.first-1]);
    }
    cout << dp[coord-1];
    return 0;
}