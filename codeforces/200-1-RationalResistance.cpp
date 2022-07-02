//
// Created by wu on 2022/6/3.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;


int main(void) {
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    if (b > a) {
        swap(a,b);
    }
    while (a&&b) {
        ans += a/b;
        a %= b;
        swap(a,b);
    }
    cout << ans;
    return 0;
}
