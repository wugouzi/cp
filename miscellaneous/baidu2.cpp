#include <iostream>
#include <unordered_set>
using namespace std;

bool check(string &s) {
  unordered_set<char> ch;
  for (auto &c: s) {
    if (ch.count(c)) return false;
    ch.insert(c);
  }
  return true;
}

string ans;

void make(string &a, string &b, string &c) {
  if (c.size() == a.size() && check(c)) {
    ans = c;
    return;
  }
  if (!ans.empty()) return;
  int i = c.size();
  c.push_back(a[i]);
  make(a, b, c);
  c.pop_back();
  c.push_back(b[i]);
  make(a, b, c);
  c.pop_back();
}

int main() {
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  unordered_set<char> check_set;
  for (auto &c: a)
    check_set.insert(c);
  for (auto &c: b)
    check_set.insert(c);
  if (check_set.size() < n) {
    cout << -1;
    return 0;
  }
  string c;
  make(a, b, c);
  if (ans.empty()) {
    cout << -1;
  } else {
    cout << ans;
  }
}
// 26 aaaaaaaaaaaaaaaaaaaaaaaaaa abcdefghijklmnopqrstuvwxyz
// abcdefghijklmnopqrstuvwxyz