//
// Created by wu on 2022/5/1.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> pa;

int find(int x) {
    while (pa[x] != x) {
        pa[x] = pa[pa[x]];
        x = pa[x];
    }
    return x;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    pa[y] = x;
    return;
}

int main(void) {
    int n, m, src, dst;
    cin >> n >> m;
    pa.resize(n+1);
    for (int i = 0; i <= n; i++)
        pa[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> src >> dst;
        merge(src, dst);
    }
    int prev = -1;
    vector<pair<int,int>> ans;
    for (int i = 1; i <= n; i++)
        if (pa[i] == i && prev == -1)
            prev = i;
        else if (pa[i] == i) {
            ans.emplace_back(prev, i);
            prev = i;
        }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << ' ' << ans[i].second<<endl;
    }
}