//
// Created by wu on 2022/5/25.
//

#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

int n,m,k,t1,t2,t3;
priority_queue<int, vector<int>, greater<int>> q;
vector<bool> visited;

int main(void) {

    cin >> n >> m >> k;
    visited.resize(n);
    vector<vector<pp>> edge(n);
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        edge[t1-1].push_back(mp(t2-1,t3));
    }

    return 0;
}
