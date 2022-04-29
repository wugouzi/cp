//
// Created by wu on 2022/4/27.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, sessionTime;
    cin >> n >> sessionTime;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i];
    int m = 1 << n;
    vector<pair<int,int>> best(m, {n,sessionTime+1});
    best[0] = {0, 0};
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                auto op = best[i^(1<<j)];
                if (op.second+tasks[j] <= sessionTime)
                    op.second += tasks[j];
                else {
                    op.first++;
                    op.second = tasks[j];
                }
                best[i] = min(best[i], op);
            }
        }
    }
    cout << best[m-1].first+1;
    return 0;
}