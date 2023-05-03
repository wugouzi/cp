#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dirs = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};

int n, m, d;

using pp = pair<int,int>;
pp next(pp xy)  {
  int x = xy.first, y = xy.second;
  int dx = dirs[d][0], dy = dirs[d][1];
  if (x == 0 && y == 0 && d == 3) d = 0;
  else if (x == n-1 && y == 0 && d == 1) d = 2;
  else if (x == 0 && y == m-1 && d == 2) d = 1;
  else if (x == n-1 && y == m-1 && d == 0) d = 3;
  else if (x == 0 && dx < 0) d -= 2;
  else if (x == n-1 && dx > 0) d += 2;
  else if (y == 0 && dy < 0) d -= 1;
  else if (y == m-1 && dy > 0) d += 1;
  pp ret = xy;
  ret.first = x + dirs[d][0];
  ret.second = y + dirs[d][1];
  return ret;
}

int main(void) {
  cin >> n >> m;
  int i, j;
  string dd;
  cin >> i >> j;
  cin >> dd;
  i--,j--;
  if (dd == "DR") d = 0;
  else if (dd == "DL") d = 1;
  else if (dd == "UR") d = 2;
  else if (dd == "UL") d = 3;
  pp xy = make_pair(i, j);
  pp ori_xy = xy;
  int ans = 1;
  xy = next(xy);
  while (xy != ori_xy) {
    ans++;
    xy = next(xy);
  }
  cout << ans;
}