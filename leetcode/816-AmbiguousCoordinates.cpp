#include "leetcode.h"
#include <cstddef>
#include <string_view>

vector<string> emu(string_view s) {
  vector<string> ans;
  int n = s.length();

  if (n == 1) {
      ans.push_back(string(s));
    return ans;
  }
  if (s[0] == '0') {
    string tp = "0.";
    tp += s.substr(1, n-1);
    ans.push_back(tp);
    return ans;
  } else {
      ans.push_back(string(s));
  }
  for (int i = 1; i < n; i++) {
    string tp(&s[0], i);
    tp += ".";
    tp += s.substr(i, n-i);
    ans.push_back(tp);
  }
  return ans;
}
vector<string> ambiguousCoordinates(string s) {
  vector<string> ans;
  int n = s.size();
  int all_zero = 0;
  for (size_t i = 2; i < n-1; i++) {
    if (all_zero != 1) {
      vector<string> s1 = emu({&s[1], i-1});
      vector<string> s2 = emu({&s[i], n-i-1});
      for (auto &s : s1) {
        for (auto &t : s2)
          ans.push_back("("+s+", "+t+")");
      }
    }
    if (s[i] == '0' && all_zero == 0)
      all_zero = 1;
    if (s[i] != '0' && all_zero == 0)
      all_zero = 2;
    if (all_zero == 1 && s[i] != '0') {
      all_zero = 2;
    }
  }
  return ans;
}

int main(void) {
  auto tp = ambiguousCoordinates("(00011)");
  for (auto &s : tp) cout << s << ' ';
}
