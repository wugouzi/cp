//
// Created by wu on 2022/4/22.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> price(n), page(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> page[i];
    vector<int> dp(k+1);
    for (int i = 0; i < n; i++)
        for (int j = k; j >= price[i]; j--)
            dp[j] = max(dp[j], dp[j-price[i]]+page[i]);
    cout << dp[k];
    return 0;
}