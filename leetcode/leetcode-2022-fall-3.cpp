//
// Created by wu on 2022/9/24.
//

#include "leetcode.h"

vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1},{-1,0}};
vector<vector<pair<bool,int>>> g;
int n, m;
int swiD(char c, int d) {
    if (c == 'E') {
        return (d+1)%4;
    }
    if (c == 'W') {
        return (d+4-1)%4;
    }
    return d;
}
vector<vector<int>> ans;
bool dfs(vector<string>& plate, int x, int y, int d, int s) {
    if (g[x][y].second != -1 && g[x][y].second == d)
        return g[x][y].first;

    if (plate[x][y] == 'O') {
        g[x][y] = make_pair(true, d);
        return true;
    }
    if (s == 0) {
        g[x][y] = make_pair(false, d);
        return false;
    }
    int dd = swiD(plate[x][y], d);
    int i = x + dirs[dd][0];
    int j = y + dirs[dd][1];

    if (i < 0 || i >= n || j < 0 || j >= m) {
        g[x][y] = make_pair(false, d);
        return false;
    }

    g[x][y] = make_pair(dfs(plate, i, j, dd, s-1), d);

    return g[x][y].first;
}
vector<vector<int>> ballGame(int num, vector<string>& plate) {
    n = plate.size();
    m = plate[0].size();
    g.resize(n, vector<pair<bool,int>>(m, {false,-1}));
    for (int i = 1; i < n-1; i++) {
        if (plate[i][0] == '.') {
            dfs(plate, i, 0, 0, num);
            if (g[i][0].first)
                ans.push_back(vector<int>{i,0});
        }
        if (plate[i][m-1] == '.') {
            dfs(plate, i, m - 1, 2, num);
            if (g[i][m - 1].first)
                ans.push_back(vector<int>{i, m - 1});
        }
    }
    for (int j = 1; j < m-1; j++) {
        if (plate[0][j] == '.') {
            dfs(plate, 0, j, 1, num);
            if (g[0][j].first)
                ans.push_back(vector<int>{0,j});
        }
        if (plate[n-1][j] == '.') {
            dfs(plate, n-1, j, 3, num);
            if (g[n-1][j].first)
                ans.push_back(vector<int>{n-1,j});
        }

    }
    return ans;
}

int main(void) {
    // int k = 4;
    // vector<string> tp = {"..E.",".EOW","..W."};
    int k = 3;
    vector<string> tp = {".....","....O","....O","....."};
    vector<vector<int>> tpp = ballGame(k, tp);
    for (auto& i : tpp) {
        cout << '[' << i[0] << ',' << i[1] << "], ";
    }
}