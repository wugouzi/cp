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

/*
acca
abca
abcba
dccz
aacba
 */

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();
  vector<int> dif;
  for (int i = 0; i < n/2; i++) {
    if (s[i] != s[n-i-1])
      dif.push_back(i);
  }
  if (dif.size() == 2) {
    char c1 = min(s[dif[0]], s[n-dif[0]-1]);
    char c2 = min(s[dif[1]], s[n-dif[1]-1]);
    s[dif[0]] = s[n-dif[0]-1] = c1;
    s[dif[1]] = s[n-dif[1]-1] = c2;
  } else if (dif.size() == 1) {
    if (s[dif[0]] == 'a' && n % 2 == 1) {
      s[n-dif[0]-1] = s[n/2] = 'a';
    } else {
      s[dif[0]] = s[n-dif[0]-1] = 'a';
    }
  } else {
    for (int i = 0; i < (n+1)/2; i++) {
      if (s[i] != 'a') {
        s[i] = s[n-i-1] = 'a';
        break;
      }
    }
  }
  cout << s;
  return 0;
}
