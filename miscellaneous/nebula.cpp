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

class Node {
 public:
  int val;
  Node *next;
  Node (int k, Node *n) : val(k), next(n) {}
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  Node *l1 = new Node(-1,nullptr);
  Node *l2 = new Node(-1,nullptr);
  // read l1
  Node *tp = l1;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    tp->next = new Node(a, nullptr);
    tp = tp->next;
  }
  // read l2
  tp = l2;
  for (int i = 0; i < m; i++) {
    cin >> a;
    tp->next = new Node(a, nullptr);
    tp = tp->next;
  }
  tp = l1;
  l1 = l1->next;
  delete tp;
  tp = l2;
  l2 = l2->next;
  delete tp;

  Node *res = new Node(-1, nullptr);
  Node *head = res;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      res->next = l1;
      l1 = l1->next;
    } else {
      res->next = l2;
      l2 = l2->next;
    }
    res = res->next;
  }
  if (l1) {
    res->next = l1;
  }
  if (l2) {
    res->next = l2;
  }
  res = head;
  head = head->next;
  while (head) {
    cout << head->val << ' ';
    head = head->next;
  }
  while (res) {
    tp = res;
    res = res->next;
    delete tp;
  }
  return 0;
}


/*
3 4
1 4 5
2 3 7 8
*/
