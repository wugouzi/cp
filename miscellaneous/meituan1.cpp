#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, a;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> a;
    nums[i] = a;
  }
  unordered_map<int, int> mp;
  int l = 0, r = 0, ans = 0;
  while (r < n) {
    while (!mp.count(nums[r]) && mp.size() == k) {
      mp[nums[l]]--;
      if (mp[nums[l]] == 0)
        mp.erase(nums[l]);
      l++;
    }
    mp[nums[r]]++;
    ans = max(r - l + 1, ans);
    r++;
  }
  cout << ans;

  return 0;
}
