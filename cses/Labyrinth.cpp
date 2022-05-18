//
// Created by wu on 2022/4/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;


int main(void) {
    int n, m, sx, sy, ex, ey;
    fstream f("../cses/test_input.txt");
    cin >> n >> m;
    //f >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> pa(n, vector<char>(m, 'a'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            //f >> grid[i][j];
            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'B') {
                ex = i;
                ey = j;
                grid[i][j] = '.';
            }
        }
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            //cout << x << ' ' << y << endl;
            if (x == ex && y == ey) {
                queue<pair<int, int>> empty;
                swap(q, empty);
                break;
            }
            if (grid[x][y] == '#')
                continue;
            grid[x][y] = '#';
            if (x+1<n && grid[x+1][y] == '.') {
                pa[x+1][y] = 'D';
                q.emplace(x+1,y);
            }
            if (y+1<m && grid[x][y+1] == '.') {
                pa[x][y+1] = 'R';
                q.emplace(x,y+1);
            }
            if (x>0 && grid[x-1][y] == '.') {
                pa[x-1][y] = 'U';
                q.emplace(x-1,y);
            }
            if (y>0 && grid[x][y-1] == '.') {
                pa[x][y - 1] = 'L';
                q.emplace(x, y - 1);
            }
    }
    if (pa[ex][ey] == 'a') {
        cout << "NO";
        return 0;
    }
    string ans;
    int x = ex, y = ey;
    while (x != sx || y != sy) {
        ans.push_back(pa[x][y]);
        switch(pa[x][y]) {
            case 'L':
                y++;
                break;
            case 'D':
                x--;
                break;
            case 'U':
                x++;
                break;
            case 'R':
                y--;
                break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl << ans.size() << endl << ans;
}