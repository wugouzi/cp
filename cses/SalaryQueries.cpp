#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

class node {
 public:
  int val = 0;
  int lazy = 0;
  node *l = nullptr;
  node *r = nullptr;
};

void update(node *u, int l, int r, int L, int R, int dif) {
  if (L <= l && R >= r) {
    u->val += dif;
    return;
  }
  int mid = (l+r)/2;
  if (L <= mid) {
    if (!u->l)
      u->l = new node;
    update(u->l, l, mid, L, R, dif);
  }
  if (R > mid) {
    if (!u->r)
      u->r = new node;
    update(u->r, mid+1, r, L, R, dif);
  }
  u->val = (u->l ? u->l->val : 0) + (u->r ? u->r->val : 0);
}

int query(node *u, int l, int r, int L, int R) {
  if (!u) return 0;
  if (L > r || R < l) return 0;
  if (L <= l && R >= r) {
      return u->val;
  }

  int mid = (l+r)/2;
  return query(u->l, l, mid, L, R) + query(u->r, mid+1, r, L, R);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, q, a, b;
  int ww = 1e9;
  char k;
  node *root = new node;
  cin >> n >> q;
  int salary[n];
  for (int i = 0; i < n; i++) {
    cin >> salary[i];
    update(root, 1, ww, salary[i], salary[i], 1);
  }
  while (q--) {
    cin >> k >> a >> b;
    if (k == '?') {
      cout << query(root, 1, ww, a, b) << '\n';
    } else {
      a--;
      update(root, 1, ww, salary[a], salary[a], -1);
      salary[a] = b;
      update(root, 1, ww, b, b, 1);
    }
  }
  return 0;
}


/*
input
10 10
9 9 1 4 3 2 10 1 2 1
! 5 1
 */
