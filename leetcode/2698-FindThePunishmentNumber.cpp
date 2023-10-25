//
// Created by wu on 2023/10/25.
//

#include "leetcode.h"

bool check;
int h(string::iterator a, string::iterator b) {
  int cur = 0;
  for (; a != b; a++)
    cur = cur * 10 + *a - '0';
  cur = cur * 10 + *a - '0';
  return cur;
}
void help(string::iterator begin, string::iterator end, int cur, int tar) {
  if (begin == end && cur == tar) check = true;
  if (check) return;
  for (auto iter = begin; iter != end; iter++) {
    int t = h(begin, iter);
    if (cur + t > tar) return;
    help(next(iter), end, cur + t, tar);
  }
}

int punishmentNumber(int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    check = false;
    auto str = to_string(i * i);
    help(str.begin(), str.end(), 0, i);
    if (check) {
      ans += i * i;
      cout << i << endl;
    }
  }
  return ans;
}

int main(void){
  cout << punishmentNumber(10);
}