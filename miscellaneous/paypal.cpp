// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <fstream>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getMostVisited' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY sprints
 */
// const int N = 400100;
const int N = 40;
int tree[N], lazy[N];
void push(int u, int l, int r) {
    if (l == r) {
        tree[u] += lazy[u];
        lazy[u] = 0;
        return;
    }
    lazy[u*2] += lazy[u];
    lazy[u*2+1] += lazy[u];
    lazy[u] = 0;
}
void update(int u, int l, int r, int L, int R) {
    if (R < l || L > r) return;
    if (L <= l && R >= r) {
        if (l == r) tree[u]++;
        else lazy[u]++;
        return;
    }
    int mid = (l+r)/2;
    push(u, l, r);
    if (L <= mid)
        update(u*2, l, mid, L, R);
    if (R > mid)
        update(u*2+1, mid+1, r, L, R);
    tree[u] = max(tree[u*2] + lazy[u*2], tree[u*2+1] + lazy[u*2+1]);
}
int query(int u, int l, int r) {
    if (l == r) return l;
    int mid = (l+r)/2;
    push(u, l, r);
    if (tree[u*2] + lazy[u*2] >= tree[u*2+1] + lazy[u*2+1])
        return query(u*2, l, mid);
    return query(u*2+1, mid+1, r);
}

int getMostVisited(int n, vector<int> sprints) {
    for (int i = 1; i < sprints.size(); i++) {
        update(1, 1, n, min(sprints[i-1], sprints[i]), max(sprints[i-1], sprints[i]));
    }
    return query(1, 1, n);
}

int main()
{
    int n = 10;
    vector<int> sprints{1,5,10,3};;
    cout << getMostVisited(n, sprints);
    return 0;
}


