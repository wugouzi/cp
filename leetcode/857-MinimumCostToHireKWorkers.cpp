//
// Created by wu on 2022/9/11.
//

#include "leetcode.h"

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<int> f(n);
    for (int i = 0; i < n; i++) f[i] = i;
    sort(f.begin(), f.end(), [&](const int s1, const int s2) {
        return wage[s1] * quality[s2] < wage[s2] * quality[s1];
    });
    priority_queue<int> q;
    int totalq = 0;
    for (int i = 0; i < k-1; i++) {
        totalq += quality[f[i]];
        q.push(quality[f[i]]);
    }
    double ans = 1e9;
    for (int i = k-1; i < n; i++) {
        totalq += quality[f[i]];
        q.push(quality[f[i]]);
        cout << f[i] << ' ' << totalq << ' ' << wage[f[i]] << ' ' << quality[f[i]] << ' ' << q.top() << endl;
        ans = min(ans, totalq * ((double)wage[f[i]]/ quality[f[i]]));
        totalq -= q.top();
        q.pop();
    }
    return ans;
}

int main(void) {
    vector<int> q = {3,1,10,10,1};
    vector<int> w = {4,8,2,2,7};
    int k = 3;
    cout << mincostToHireWorkers(q,w,k);
}