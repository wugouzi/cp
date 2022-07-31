//
// Created by wu on 2022/4/23.
//

#include "leetcode.h"

double cross(const vector<int>& x, const vector<int>& y, const vector<int>& z) {
    return (y[0]-x[0])*(z[1]-y[1])-(y[1]-x[1])*(z[0]-y[0]);
}

int dist(const vector<int>& a, const vector<int>& b) {
    return (b[1]-a[1])*(b[1]-a[1])+(b[0]-a[0])*(b[0]-a[0]);
}

vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    vector<vector<int>> ans;
    int my = 0, n = trees.size();
    for (int i = 1; i < n; i++) {
        if (trees[i][1] < trees[my][1])
            my = i;
    }
    swap(trees[my], trees[0]);
    sort(trees.begin()+1,trees.end(), [&](const vector<int> &a, const vector<int> &b) {
        double diff = cross(trees[0], a, b) - cross(trees[0], b, a);
        if (diff == 0)
            return dist(trees[0], a) < dist(trees[0], b);
        else
            return diff > 0;
    });
    int r = n-1;
    while (r >= 0 && cross(trees[0], trees[r], trees[n-1]) == 0)
        r--;
    reverse(trees.begin()+r+1, trees.end());
    for (int i = 0; i < n; i++) {
        if (ans.size() < 3) {
            ans.push_back(trees[i]);
        }
        else {
            while (ans.size() > 2 && cross(ans.end()[-2], ans.end()[-1], trees[i])<0)
                ans.pop_back();
            ans.push_back(trees[i]);
        }
    }

    return ans;
}

int main(void) {
    vector<vector<int>> t = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    vector<vector<int>> tp = outerTrees(t);
    for (int i = 0; i < tp.size(); i++) cout << '[' << tp[i][0] << ',' << tp[i][1] << "] ";
}