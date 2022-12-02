#include "leetcode.h"
#include <string>
#include <unordered_map>
#include <vector>

int kmask;
int ans, n, m;
vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
int shortestPathAllKeys(vector<string>& grid) {
  kmask = 0;
  n = grid.size(), m = grid[0].size();
  vector<int> v(3);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c = grid[i][j];
      if ('a' <= c && c <= 'z')
        kmask++;
      if (c == '@') {
        v[0] = i, v[1] = j, v[2] = 0;
      }
    }
  kmask = (1 << kmask) - 1;
  ans = -1;
  queue<vector<int>> q;
  q.push(v);
  int t = 0;
  unordered_map<int, unordered_map<int, unordered_map<int, bool>>> vis;
  while (!q.empty()) {
    int k = q.size();
    t++;
    while (k--) {
      auto s = q.front();
      int x = s[0], y = s[1], mask = s[2];
      q.pop();
      vis[x][y][mask] = true;
      for (auto &dir : dirs) {
        int i = x+dir[0], j = y+dir[1];
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#') {
          vector<int> v{i, j, 0};
          char c = grid[i][j];
          int m = mask;
          if ('a' <= c && c <= 'z')
            m |= 1 << (c - 'a');
          if (m == kmask) {
            return t;
          }
          if (vis[i][j][m])
            continue;
          if ('A' <= c && c <= 'Z' && !(m & (1 << (c - 'A'))))
            continue;
          v[2] = m;
          q.push(v);
        }
      }
      vis[x][y][mask] = false;
    }
  }
  return ans;
}


int main(void) {
  vector<string> s = {"@abcdeABCDEFf"};
  cout << shortestPathAllKeys(s);
}
