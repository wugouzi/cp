#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;


int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  fstream f("input");
  string t;
  // int ans = 0;
  int sum = 0;
  vector<int> ans;
  while (getline(f, t)) {
    if (t.size() > 0) {
      sum += stoi(t);
    } else {
      // ans = max(ans, sum);
      ans.push_back(sum);
      sum = 0;
    }
  }
  sort(ans.begin(), ans.end());
  int n = ans.size() - 1;
  cout << ans[n] + ans[n-1] + ans[n-2];
  return 0;
}
