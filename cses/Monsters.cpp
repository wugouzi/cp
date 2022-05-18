//
// Created by wu on 2022/5/3.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

typedef pair<int,int> P;

int main(void) {
    fstream f("../cses/test_input.txt");
    int n, m;
    cin >> n >> m;
    //f>>n>>m;
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<char> dirsc = {'R','L','D','U'};
    vector<vector<char>> grid(n,vector<char>(m)), pa(n,vector<char>(m));
    vector<vector<bool>> mon(n, vector<bool>(m));
    queue<P> aq, mq;
    int xx,yy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            //f>>grid[i][j];
            if (grid[i][j] == 'A') {
                aq.push(make_pair(i,j));
                pa[i][j] = '#';
                xx = i, yy = j;
            }
            else if (grid[i][j] == 'M') {
                mq.push(make_pair(i, j));
                mon[i][j] = true;
            }
        }
    if (xx == 0 || xx == n-1 || yy == 0 || yy == m-1) {
        cout << "YES" << endl << "0";
        return 0;
    }
    while (!aq.empty()) {
        int k = mq.size();
        while (k--) {
            P tp = mq.front();
            int x = tp.first, y = tp.second;
            mq.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x+dirs[i][0], newy = y+dirs[i][1];
                if (newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] == '#' || mon[newx][newy])
                    continue;
                mon[newx][newy] = true;
                mq.push(make_pair(newx,newy));
            }
        }
        k = aq.size();
        while (k--) {
            P tp = aq.front();
            int x = tp.first, y = tp.second;
            aq.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x+dirs[i][0], newy = y+dirs[i][1];
                if (newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] == '#' || mon[newx][newy] || pa[newx][newy])
                    continue;
                if (newx == 0 || newx == n-1 || newy == 0 || newy == m-1) {
                    pa[newx][newy] = dirsc[i];
                    x = newx, y = newy;
                    string ans;
                    while (grid[x][y] != 'A') {
                        ans += pa[x][y];
                        switch (pa[x][y]) {
                            case 'L':
                                y++;break;
                            case 'R':
                                y--;break;
                            case 'D':
                                x--;break;
                            case 'U':
                                x++;break;
                        }
                    }
                    cout << "YES" << endl << ans.size() << endl;
                    for (int i = (int)ans.size()-1; i >= 0; i--)
                        cout << ans[i];
                    return 0;
                }
                pa[newx][newy] = dirsc[i];
                aq.push(make_pair(newx,newy));
            }
        }
    }
    cout << "NO";
}