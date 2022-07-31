//
// Created by wu on 2022/5/10.
//

#include "leetcode.h"

/*bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> catg(n, vector<bool>(m)),mouseg(n, vector<bool>(m));
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    int cx,cy,mx,my,fx,fy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'C') {
                cx = i;cy = j;
            } else if (grid[i][j] == 'M') {
                mx = i;my = j;
            } else if (grid[i][j] == 'F') {
                fx = i;fy = j;
            }
    }
    typedef pair<int,int> P;
    queue<P> cat, mouse;
    cat.push(make_pair(cx,cy));
    catg[cx][cy] = true;
    mouseg[mx][my] = true;
    mouse.push(make_pair(mx,my));
    int mmove = 0;
    while (!catg[fx][fy] && !mouse.empty()) {
        int k = cat.size();
        while (k--) {
            P cp = cat.front();
            int x = cp.first, y = cp.second;
            cat.pop();
            for (auto& dir : dirs) {
                for (int i = 1; i <= catJump; i++) {
                    int newx = x+i*dir[0], newy = y+i*dir[1];
                    if (newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy]=='#')
                        break;
                    if (catg[newx][newy])
                        continue;
                    catg[newx][newy] = true;
                    cat.push(make_pair(newx,newy));
                }
            }
        }
        k = mouse.size();
        while (k--) {
            P mp = mouse.front();
            int x = mp.first, y = mp.second;
            mouse.pop();
            for (auto& dir : dirs) {
                for (int i = 1; i <= mouseJump; i++) {
                    int newx = x+i*dir[0], newy = y+i*dir[1];
                    if (newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy]=='#')
                        break;
                    if (newx == fx && newy == fy)
                        return true;
                    if (catg[newx][newy] || mouseg[newx][newy])
                        continue;
                    mouseg[newx][newy] = true;
                    mouse.push(make_pair(newx,newy));
                }
            }
        }
        mmove++;
        if (mmove > 1000)
            return false;
    }
    return false;
}*/


/*bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
    int color[8][8][8][8][2], degree[8][8];
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            degree[i][j] = max(0,min(j,catJump))+max(0,min(m-1-j,catJump))
                    +max(0,min(i,catJump))+max(0,min(n-1-i,catJump));
            for (int ii = 0; ii < n; ii++)
                for (int jj = 0; jj < n; jj++) {
                    color[i][j][ii][jj][0] = color[i][j][ii][jj][1] = -1;
                }
        }

    int cx,cy,mx,my,fx,fy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'C')
                cx = i, cy = j;
            else if (grid[i][j] == 'M')
                mx = i, my = j;
            else if (grid[i][j] == 'F')
                fx = i, fy = j;
    queue<vector<int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            color[fx][fy][i][j][0] = color[fx][fy][i][j][1] = 1;
            q.push(vector<int>{fx,fy,i,j,0,1});
            q.push(vector<int>{fx,fy,i,j,1,1});
            if (fx != i || fy != j) {

            }
        }
    while (!q.empty()) {
        vector<int> tp = q.front();
        q.pop();
        int mx1 = tp[0], my1 = tp[1], cx1 = tp[2], cy1 = tp[3], t = tp[4], win = tp[5];
        // o is mouse
        if (t == 1) {
            for (auto& dir : dirs) {
                for (int l = 1; l <= mouseJump; l++) {
                    int mx2 = mx1+l*dir[0], my2 = my1+l*dir[1];
                    if (mx2 < 0 || my2 < 0 || mx2 >= n || my2 >= m || grid[mx2][my2] == '#' || visited[mx2][my2][cx1][cy1][0])
                        break;
                    visited[mx2][my2][cx1][cy1][0] = 1;
                    if (color[mx1][my1][cx1][cy1][1] == 1) {
                        color[mx2][my2][cx1][cy1][0] = 1;
                        cout << mx2 << ' ' << my2 << ' ' << cx1 << ' ' << cy1 << ' ' << 0 << 1 << endl;
                        q.push(vector<int>{mx2,my2,cx1,cy1,0,1});
                    }
                }
            }
        } else if (t == 0) {
            for (auto& dir : dirs) {
                for (int l = 1; l <= catJump; l++) {
                    int cx2 = cx1+l*dir[0], cy2 = cy1+l*dir[1];
                    if (cx2 < 0 || cy2 < 0 || cx2 >= n || cy2 >= m || grid[cx2][cy2] == '#' || visited[mx1][my1][cx2][cy2][1])
                        break;
                    if (grid[cx2][cy2] == '#')
                        degree[cx2][cy2]--;
                    visited[mx1][my1][cx2][cy2][1] = 1;
                    if (color[mx1][my1][cx1][cy1][0] == 1) {
                        degree[cx2][cy2]--;
                    }
                    if (!degree[cx2][cy2]) {
                        color[mx1][my1][cx2][cy2][1] = 1;
                        cout << mx1 << ' ' << my1 << ' ' << cx2 << ' ' << cy2 << ' ' << 0 << 1 << endl;
                        q.push(vector<int>{mx1,my1,cx2,cy2,1,1});
                    }
                }
            }
        }
    }
    return color[mx][my][cx][cy][0];
}
*/

int dp[100][8][8][8][8][2];
int fx, fy, mj, cj, n, m;
vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
int dfs(vector<string>& grid, int t, int mx, int my, int cx, int cy, int c) {
    //cout << t << ' ' << mx << ' ' << my << ' ' << cx << ' ' << cy << ' ' << c << endl;
    if (cx == fx && cy == fy)
        return 0;
    if (cx == mx && cy == my)
        return 0;
    if (mx == fx && my == fy)
        return 1;
    if (t >= 100)
        return 0;
    int& val = dp[t][mx][my][cx][cy][c];
    if (val != -1)
        return val;
    //mouse move
    if (c == 0) {
        val = 0;
        for (auto& dir : dirs) {
            for (int l = 0; l <= mj; l++) {
                int nmx = mx+dir[0]*l, nmy = my+l*dir[1];
                if (nmx < 0 || nmy < 0 || nmx >= n || nmy >= m ||
                grid[nmx][nmy] == '#')
                    break;
                val = dfs(grid,t+1,nmx,nmy,cx,cy,1-c);
                if (val == 1)
                    return 1;
            }
        }
    } else if (c == 1) {
        val = 1;
        for (auto& dir : dirs) {
            for (int l = 0; l <= cj; l++) {
                int ncx = cx+dir[0]*l, ncy = cy+l*dir[1];
                if (ncx < 0 || ncy < 0 || ncx >= n || ncy >= m ||
                    grid[ncx][ncy] == '#')
                    break;
                val &= dfs(grid,t+1,mx,my,ncx,ncy,1-c);
                if (val == 0)
                    return 0;
            }
        }
    }
    return val;
}
bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
    cj = catJump, mj = mouseJump;
    n = grid.size(), m = grid[0].size();
    memset(dp,-1,sizeof(dp));
    int mx,my,cx,cy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'F')
                fx = i,fy=j;
            else if (grid[i][j] == 'M')
                mx=i,my=j;
            else if (grid[i][j] == 'C')
                cx=i,cy=j;
    int a = 1;
    return dfs(grid,0,mx,my,cx,cy,0);
}


int main(void) {
    vector<string> grid = {"####F","#C...","M...."};
    cout << 0+ canMouseWin(grid,1,2);
}