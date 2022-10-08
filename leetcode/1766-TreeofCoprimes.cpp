#include "leetcode.h"
#include <climits>
#include <utility>
#include <vector>

vector<int> ans;
vector<pair<int,int>> ancs;
vector<vector<int>> cops;

void dfs(vector<int> &nums, vector<vector<int>> &ed, int s, vector<bool> &v, int l) {
  v[s] = true;

  int ml = -1;
  pair<int,int> tp = ancs[nums[s]];
  for (auto &t : cops[nums[s]]) {
    if (ancs[t].first != -1 && ancs[t].second > ml) {
      ml = ancs[t].second;
      ans[s] = ancs[t].first;
    }
  }
  ancs[nums[s]] = make_pair(s, l);

  for (auto &t : ed[s]) {
    if (v[t]) continue;
    dfs(nums, ed, t, v, l+1);
  }

  ancs[nums[s]] = tp;
}
vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
  int n = nums.size();
  ancs.resize(55);
  cops.resize(55);
  for (int i = 1; i <= 50; i++)
    for (int j = i; j <= 50; j++) {
      if (gcd(i, j) == 1) {
        cops[i].push_back(j);
        cops[j].push_back(i);
      }
    }

  for (auto &n : ancs)
    n = make_pair(-1, -1);

  ans.resize(n, -1);
  vector<vector<int>> E(n);
  vector<bool> v(n, false);
  for (auto &e : edges) {
    E[e[0]].push_back(e[1]);
    E[e[1]].push_back(e[0]);
  }
  dfs(nums, E, 0, v, 0);
  return ans;
}


int main(void) {
  vector<int> n{9,16,30,23,33,35,9,47,39,46,16,38,5,49,21,44,17,1,6,37,49,15,23,46,38,9,27,3,24,1,14,17,12,23,43,38,12,4,8,17,11,18,26,22,49,14,9};
  vector<vector<int>> e{{17,0},{30,17},{41,30},{10,30},{13,10},{7,13},{6,7},{45,10},{2,10},{14,2},{40,14},{28,40},{29,40},{8,29},{15,29},{26,15},{23,40},{19,23},{34,19},{18,23},{42,18},{5,42},{32,5},{16,32},{35,14},{25,35},{43,25},{3,43},{36,25},{38,36},{27,38},{24,36},{31,24},{11,31},{39,24},{12,39},{20,12},{22,12},{21,39},{1,21},{33,1},{37,1},{44,37},{9,44},{46,2},{4,46}};
  auto tp = getCoprimes(n, e);
  for (auto &n : tp) cout << n << ' ';
}
