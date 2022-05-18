//
// Created by wu on 2022/5/17.
//

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <fstream>

using namespace std;
typedef pair<long long,int> P;
int main(void){
    int n, m, tp1, tp2, tp3;
    fstream f("../cses/test_input.txt");
    cin >> n >> m;
    //f >> n >> m;
    //spfa

    vector<vector<pair<int,int>>> edge(n);
    for (int i = 0; i < m; i++) {
        cin >> tp1 >> tp2 >> tp3;
        //f >> tp1 >> tp2 >> tp3;
        edge[tp1-1].push_back(make_pair(tp2-1,tp3));
    }
    vector<long long> dist(n,-1);
    vector<bool> p(n,false);
    dist[0] = 0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.emplace(0,0);
    while (!q.empty()) {
        int s = q.top().second;
        q.pop();
        if (p[s])
            continue;
        p[s] = true;
        for (auto& p : edge[s]) {
            int t = p.first, ww = p.second;
            if (dist[t] == -1 || dist[t] > dist[s]+ww) {
                dist[t] = dist[s]+ww;
                q.emplace(dist[t],t);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << dist[i] << ' ';

    /*  bellman-ford
    vector<vector<int>> edge;
    for (int i = 0; i < m; i++) {
        cin >> tp1 >> tp2 >> tp3;
        edge.push_back({tp1-1,tp2-1,tp3});
    }
    vector<long long> dist(n,INT_MAX);
    dist[0] = 0;
    for (int i = 0; i < n-1; i++) {
        for (auto& e : edge) {
            int a = e[0], b = e[1], c = e[2];
            dist[b] = min(dist[b], c+dist[a]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << dist[i] << ' ';
    */
}