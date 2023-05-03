//
// Created by wu on 2023/3/28.
//

#include <iostream>
#include <vector>

using namespace std;

int count2(int x) {
    int ret = 0;
    while (x && !(x % 2)) {
        x /= 2;
        ret++;
    }
    return ret;
}

int count5(int x) {
    int ret = 0;
    while (x && !(x % 5)) {
        x /= 5;
        ret++;
    }
    return ret;
}

const int N = 100100;
int num2[N], num5[N], lazy2[N], lazy5[N];
vector<vector<int>> E;
void push(int i) {
    num2[i] += lazy2[i];
    num5[i] += lazy5[i];
    for (auto &j : E[i]) {
        lazy2[j] += lazy2[i];
        lazy5[j] += lazy5[i];
    }
}

void dfs(int i) {
    push(i);
    for (auto &j : E[i]) {
        dfs(j);
        num2[i] += num2[j];
        num5[i] += num5[j];
    }
}

int main(void) {
    int n;
    cin >> n;
    E.resize(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        num2[i] = count2(a);
        num5[i] = count5(a);
    }
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        E[a-1].push_back(b-1);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        lazy2[a-1] += count2(b);
        lazy5[a-1] += count5(b);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << min(num2[i], num5[i]) << ' ';
    }
}