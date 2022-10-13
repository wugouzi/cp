//
// Created by wu on 2022/10/11.
//

#include "leetcode.h"

int checkWays(vector<vector<int>> &pairs) {
    unordered_map<int, unordered_map<int, bool>> mp;
    vector<int> nodes;
    for (auto &p: pairs) {
        mp[p[0] - 1][p[1] - 1] = true;
        mp[p[1] - 1][p[0] - 1] = true;
    }
    for (auto &[k, _]: mp)
        nodes.push_back(k);
    sort(nodes.begin(), nodes.end(), [&](const int &s1, const int &s2) {
        return mp[s1].size() >= mp[s2].size();
    });
    int n = mp.size();
    if (mp[nodes[0]].size() != n - 1) return 0;
    function<int(int)> deg = [&mp](int s) {
        return mp[s].size();
    };
    int ans = 1;
    for (int i = 1; i < n; i++) {
        int pa = -1;
        int no = nodes[i];
        for (int j = i - 1; j >= 0; j--) {
            if (mp[no].count(nodes[j]) && deg(nodes[j]) >= deg(no)) {
                pa = j;
                break;
            }
        }
        if (pa == -1)
            return 0;
        pa = nodes[pa];
        for (auto[k, _]: mp[no]) {
            if (k != pa && !mp[pa].count(k))
                return 0;
        }
        if (deg(pa) == deg(no)) ans = 2;
    }
    return ans;
}

int main(void) {
    vector<vector<int>> p;
    fstream f("/Users/wu/miscellaneous/code/leetcode/input");
    while (f) {
        int t1, t2;
        f >> t1;
        f >> t2;
        p.push_back(vector<int>{t1,t2});
    }
    cout << checkWays(p);
}