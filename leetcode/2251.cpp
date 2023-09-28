#include "leetcode.h"

#define RR 13
class Node {
public:
  int lazy;
  Node *left;
  Node *right;
  Node() : lazy(0), left(nullptr), right(nullptr) {}
} *root;

void push(Node *u) {
  if (!u->left)
    u->left = new Node();
  if (!u->right)
    u->right = new Node();
  u->left->lazy = u->right->lazy = u->lazy;
  u->lazy = 0;
}

void update(Node *u, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    u->lazy++;
    return;
  }
  int mid = (l + r) / 2;
  push(u);
  if (L <= mid)
    update(u->left, l, mid, L, R);
  if (R > mid)
    update(u->right, mid + 1, r, L, R);
}

int query(Node *u, int l, int r, int d) {
  if (d <= l && d >= r)
    return u->lazy;
  if (!u->left)
    return u->lazy;
  int mid = (l + r) / 2;
  int ans = 0;
  push(u);
  if (d <= mid)
    return query(u->left, l, mid, d);
  return query(u->right, mid + 1, r, d);
}

vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                             vector<int> &people) {
  root = new Node();
  for (auto &v : flowers)
    update(root, 1, RR, v[0], v[1]);
  vector<int> ans;
  for (auto &n : people)
    ans.push_back(query(root, 1, 1e9, n));
  return ans;
}

int main(void) {
  vector<vector<int>> f = {{1,6},{3,7},{9,12},{4,13}};
  vector<int> p = {2, 3, 7, 11};
  auto t = fullBloomFlowers(f, p);
  pv(t);
}
