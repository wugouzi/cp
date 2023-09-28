#include "leetcode.h"

vector<int> filterRestaurants(vector<vector<int>> &r, int veganFriendly,
                              int maxPrice, int maxDistance) {
  vector<int> ans;
  for (int i = 0; i < r.size(); i++) {
    if (veganFriendly && !r[i][2])
      continue;
    if (maxPrice < r[i][3])
      continue;
    if (maxDistance < r[i][4])
      continue;
    ans.push_back(i + 1);
  }
  sort(ans.begin(), ans.end(), [&](const int i, const int j) {
    return r[i][1] < r[j][1] || (r[i][1] == r[j][1] && i < j);
  });
  return ans;
}

int main(void) {
  vector<vector<int>> tp = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
  auto zz = filterRestaurants(tp, 1, 50, 10);
  pv(zz);
}
