#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

// int bit[300000];
// int n;

// void update(int u, int d) {
//   for (int i = u; i <= n; i += i & (-i)) {
//     bit[i] += d;
//   }
// }

// int query(int u) {
//   int ans = 0;
//   for (; u > 0; u -= u & (-u)) {
//     ans += bit[u];
//   }
//   return ans;
// }

// // 1 1 1 2 2 2 3 3 3

// int del(int u) {
//   int l = 1, r = n;
//   while (l < r) {
//     int mid = (l+r)/2;
//     int val = query(mid);
//     if (val >= u) {
//       r = mid;
//     } else {
//       l = mid + 1;
//     }
//   }
//   return l;
// }

// int main(void) {
//   ios_base::sync_with_stdio(false);
//   //cin.tie(NULL);
//   int a;
//   cin >> n;
//   memset(bit, 0, sizeof(bit));
//   for (int i = 1; i <= n; i++) {
//     update(i, 1);
//   }
//   int arr[n];
//   for (int i = 0; i < n; i++)
//     cin >> arr[i];
//   for (int i = 0; i < n; i++) {
//     cin >> a;
//     int idx = del(a);
//     update(idx, -1);
//     cout << arr[idx-1] << " ";
//   }
//   return 0;
// }


int seg[1000000];

// x is the sum we want
int query(int x, const int &m) {
  int i = 1;
  while (i < m) {
    i <<= 1;
    // ensures we find the minimum index satisfying the condition
    if (seg[i] < x) {
      x -= seg[i];
      i++;
    }
    // since the leaf nodes -1
    seg[i]--;
  }
  return i - m;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x, p;
  cin >> n;
  int m = 1;
  int arr[n];
  while (m < n) {
    m <<= 1;
  }

  // initialize leaf nodes
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    seg[i+m] = 1;
  }

  // initialize internal and root nodes
  for (int i = m-1; i; i--) {
    seg[i] = seg[i*2] + seg[i*2+1];
  }

  for (int i = 0; i < n; i++) {
    cin >> p;
    cout << arr[query(p, m)] << "\n";
  }
}
