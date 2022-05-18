//
// Created by wu on 2022/5/17.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;


void dj(vector<vector<P>>& edge, vector<long long>& dist, int s) {
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(make_pair(0,s));
    ll n = edge.size();
    dist[s] = 0;
    vector<bool> vis(n);
    while (!q.empty()) {
        ll src = q.top().second;
        q.pop();
        if (vis[src])
            continue;
        vis[src] = true;
        for (auto& e : edge[src]) {
            ll tar = e.first, w = e.second;
            if (dist[tar] == -1 || dist[tar] > dist[src]+w) {
                dist[tar] = dist[src]+w;
                q.push(make_pair(dist[tar],tar));
            }
        }
    }
}

int main(void) {
    ll n,m,t1,t2,t3;
    fstream f("../cses/test_input.txt");
    cin >> n >> m;
    //f>>n>>m;
    vector<vector<P>> edge(n),edge1(n);
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        //f>>t1>>t2>>t3;
        edge[t1-1].push_back(make_pair(t2-1,t3));
        edge1[t2-1].push_back(make_pair(t1-1,t3));
    }
    vector<long long> dist1(n,-1), dist2(n,-1);
    dj(edge,dist1,0);
    dj(edge1,dist2,n-1);
    long long ans = -1;
    for (int i = 0; i < n; i++) {
        for (auto& e : edge[i]) {
            ll j = e.first, w = e.second;
            if (dist1[i] != -1 && dist2[j] != -1) {
                ans = ans == -1 ? dist1[i]+dist2[j]+w/2 : min(ans,dist1[i]+dist2[j]+w/2);
            }
        }
    }
    cout << ans;
}