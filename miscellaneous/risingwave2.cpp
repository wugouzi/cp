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

class Machine {
public:
  vector<int> nums_;
  int get_le_count(int i);
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<Machine> machines;
  int l = INT_MIN, r = INT_MAX;
  int n = 0;
  for (auto &machine : machines) {
    n += machine.get_le_count(INT_MAX);
  }

  // suppose n is odd, k = n / 2;
  // 边界情况 r = l + 1, mid = l,
  // r > l => mid >= l
  // 无论val跟k的关系，-> l = r -> terminate
  int k = n / 2;
  // 边界点 m = l时，r = l + 1
  while (l < r) {
    int mid = (l + r) / 2;
    int val = 0;
    for (auto &m : machines) {
      val += m.get_le_count(mid);
    }
    if (val >= k)
      r = mid;
    else if (val < k)
      l = mid + 1;
  }
  cout << l;
  return 0;
}
