//
// Created by wu on 2022/4/16.
//

#include "leetcode.h"

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;
    multiset<int> q;
    vector<vector<int>> piece;
    for (auto& b : buildings) {
        piece.push_back({b[0],-b[2]});
        piece.push_back({b[1],b[2]});
    }
    sort(piece.begin(), piece.end());
    int prev = -1, cur;
    q.insert(0);
    for (auto& p : piece) {
        int x = p[0], y = p[1];
        if (y <= 0) {
            q.insert(-y);
        } else if (y >= 0) {
            q.erase(q.lower_bound(y));
        }
        cur = *q.rbegin();
        if (cur != prev) {
            ans.push_back({x,cur});
            prev = cur;
        }
    }
    return ans;
}

int main(void) {
    vector<vector<int>> b = {{0,2,3},{2,5,3}};
    b = getSkyline(b);
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[0].size(); j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }

}