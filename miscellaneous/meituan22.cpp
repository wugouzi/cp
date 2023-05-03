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
#define EPSILON 0.00001
// x > 0
// log (x * EPSILON)
double squareroot(double x) {
  if (x == 0) return 0;
  if (abs(x) < 1) return 1 / squareroot(1 / x);
  if (abs(x) == 1) return x;
  x = abs(x);
  double l = EPSILON;
  double r = x;
  while (abs(x - l * l) > EPSILON) {
    double mid = (l + r) / 2;
    if (mid * mid > x) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return l;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  double test;
  while (n--) {
    cin >> test;
    double res1 = sqrt(test);
    double res2 = squareroot(test);
    double delta = abs(res1 - res2);
    cout << test << ' ' << res1 << ' ' << res2 << ' ' << delta << endl;
  }
  return 0;
}
