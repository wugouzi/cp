#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>

using namespace std;

/*
** Strategy: Use balanced binary search tree to store the numbers
**
** Time Complexity : O(log n)
** Space Complexity : O(n)
*/

class AVLTree {
 public:
  class Node {
   public:
    int val;
    int size;
    int height;
    Node *left;
    Node *right;
    Node (int v, int s, int h, Node *l, Node *r) :
        val(v), size(s), height(h), left(l), right(r) {}
  };
  Node *top;
  int Height(Node *root) {
    if (!root) return 0;
    return root->height;
  }

  int Size(Node *root) {
    if (!root) return 0;
    return root->size;
  }

  void UpdateHeight(Node *root) {
      if (!root) return;
      root->height = max(Height(root->left), Height(root->right)) + 1;
  }

  void UpdateNode(Node *root, int dup) {
    if (!root) return;
    UpdateHeight(root);
    root->size = dup + Size(root->left) + Size(root->right);
  }

  Node *RotateRight(Node *root) {
    Node *left = root->left;
    int RootCount = Size(root) - Size(root->left) - Size(root->right);
    int LeftCount = Size(left) - Size(left->left) - Size(left->right);
    root->left = left->right;
    left->right = root;
    UpdateNode(root, RootCount);
    UpdateNode(left, LeftCount);
    return left;
  }

  Node *RotateLeft(Node *root) {
    Node *right = root->right;
    int RootCount = Size(root) - Size(root->left) - Size(root->right);
    int RightCount = Size(right) - Size(right->left) - Size(right->right);
    root->right = right->left;
    right->left = root;
    UpdateNode(root, RootCount);
    UpdateNode(right, RightCount);
    return right;
  }

  int GetFactor(Node *root) {
    if (!root) return 0;
    return Height(root->left) - Height(root->right);
  }

  Node *Balance(Node *root) {
    int factor = GetFactor(root);
    int lfactor = GetFactor(root->left);
    int rfactor = GetFactor(root->right);
    if (factor > 1 && lfactor > 0) {
      return RotateRight(root);
    } else if (factor > 1 && lfactor <= 0) {
      root->left = RotateLeft(root->left);
      return RotateRight(root);
    } else if (factor < -1 && rfactor <= 0) {
      return RotateLeft(root);
    } else if (factor < -1 && rfactor > 0) {
      root->right = RotateRight(root->right);
      return RotateLeft(root);
    } else {
      return root;
    }
  }

  void AVLInsert(Node *&root, int val) {
    if (!root) {
      root = new Node(val, 1, 1, nullptr, nullptr);
    } else if (root->val == val) {
      root->size++;
    } else {
      if (root->val < val) {
        AVLInsert(root->right, val);
      } else {
        AVLInsert(root->left, val);
      }
      UpdateHeight(root);
      root->size++;
    }
    root = Balance(root);
  }

  void Insert(int val) {
    AVLInsert(top, val);
  }



  int query(Node *root, int val) {
    if (!root) return 0;
    int ret = 0;
    if (root->val == val) ret = Size(root->left);
    if (root->val > val) ret = query(root->left, val);
    if (root->val < val) ret = root->size - Size(root->right) + query(root->right, val);
    return ret;
  }
  int Query(int val) {
    return query(top, val);
  }
};

AVLTree tree;

int mrank(int x) {
  int ret = tree.Query(x);
  tree.Insert(x);
  return ret;
}

void wrap(int x) {
  cout << mrank(x) << ' ';
}

bool test(int n) {
  AVLTree tree;
  srand(n);
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    nums.push_back(rand() % (n / 2));
    cout << nums[i] << ' ';
  }
  cout << endl;
  map<int,int> mp;
  tree.Insert(nums[0]);
  mp[nums[0]] = 1;
  for (int i = 1; i < n; i++) {
    int res1 = 0;
    for (auto &[k,v] : mp) {
      if (k < nums[i]) res1 += v;
      else break;
    }
    int res2 = tree.Query(nums[i]);
    if (res1 != res2) {
      cout << i << ' ' << nums[i] << ' ' << res1 << ' ' << res2;
      return false;
    }
    tree.Insert(nums[i]);
    mp[nums[i]]++;
  }
  return true;
}

/*
5 1 3 2 3 4
  0 1 1 2 4
 */
int main(void) {

  // test(100);
  int n;
  cin >> n;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    wrap(x);
  }
  return 0;
}
