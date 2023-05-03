#include <iostream>
#include <vector>
using namespace std;
using pp = pair<int,int>;
vector<vector<pp>> E;
int n;
int dfs(int i, vector<int> &vis) {
    int sum = 0;
    vis[i] = 1;
    for (auto &p : E[i]) {
        if (vis[p.first]) continue;
        sum += max(p.second, dfs(p.first, vis));
    }
    vis[i] = 0;
    return sum;
}
int main(void) {
    cin >> n;
    E.resize(n);
    int a, b, c;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        E[a-1].push_back(make_pair(b-1,c));
        E[b-1].push_back(make_pair(a-1,c));
    }
    vector<int> vis(n);
    cout << dfs(0, vis);
}