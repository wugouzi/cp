//
// Created by wu on 2022/5/17.
//

#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    int n,m,q, t1,t2,t3;
    cin >> n >> m >> q;
    vector<vector<long long>> edge(n,vector<long long>(n,-1));
    for (int i = 0; i < n; i++) edge[i][i] = 0;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        edge[t1-1][t2-1] = edge[t1-1][t2-1] == -1 ? t3 : min(edge[t1-1][t2-1],(long long)t3);
        edge[t2-1][t1-1] = edge[t2-1][t1-1] == -1 ? t3 : min(edge[t2-1][t1-1],(long long)t3);
    }


    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (edge[i][k] != -1 && edge[k][j] != -1) {
                    edge[i][j] = edge[i][j] == -1 ? edge[i][k]+edge[k][j] : min(edge[i][k]+edge[k][j],edge[i][j]);
                }
            }

    for (int i = 0; i < q; i++) {
        cin >> t1 >> t2;
        cout << edge[t1-1][t2-1] << endl;
    }


}