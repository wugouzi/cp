//
// Created by wu on 2022/10/10.
//

#include "leetcode.h"
using ll = long long;
ll pow(ll x, ll y, ll mod) {
    ll ans = 1;
    while (y) {
        if (y & 1)
            (ans *= x) %= mod;
        y >>= 1;
        (x *= x) %= mod;
    }
    return ans;
}
int waysToBuildRooms(vector<int>& prevRoom) {
    int mod = 1e9+7;
    int n = prevRoom.size();
    vector<int> fac(n), inv(n);
    fac[0] = 1;
    inv[0] = 1;

    for (int i = 1; i < n; i++) {
        fac[i] = ((ll)fac[i-1]*i) % mod;
    }
    inv[n-1] = pow(fac[n-1], mod-2, mod);
    for (int i = n-2; i >= 1; i--) {
        inv[i] = ((ll)inv[i+1]*(i+1)) % mod;
    }
    vector<vector<int>> E(n);
    for (int i = 1; i < n; i++)
        E[prevRoom[i]].push_back(i);
    vector<ll> f(n), cnt(n);
    function<void(int)> dfs = [&](int u) {
        f[u] = 1;
        for (auto &t : E[u]) {
            dfs(t);
            f[u] = ((((ll) f[u] * f[t]) % mod) * inv[cnt[t]]) % mod;
            cnt[u] += cnt[t];
        }
        f[u] = ((ll)f[u] * fac[cnt[u]]) % mod;
        cnt[u]++;
    };
    dfs(0);
    return f[0];
}

int main(void) {
    vector<int> prev{-1,0,1};
    cout << waysToBuildRooms(prev);
}