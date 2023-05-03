#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using pp = pair<vector<int>, string>;
bool COMP(string s1, string s2) {
  if (s1 == "?") return 0;
  if (s2 == "?") return 1;
  return s1 < s2;
}
int main(void) {
  int n;
  cin >> n;
  vector<pp> res;
  string a,b,c,d,e;
  int B, C, D, E;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c >> d >> e;
    B = b == "?" ? -1 : atoi(b.c_str());
    C = c == "?" ? -1 : atoi(c.c_str());
    D = d == "?" ? -1 : atoi(d.c_str());
    E = e == "?" ? -1 : atoi(e.c_str());
    int cnt = (B == -1) + (C == -1) + (D == -1) + (E == -1);
    if (cnt == 1) {
      if (E == -1) E = B + C + D;
      else if (B == -1) B = E - C - D;
      else if (C == -1) C = E - B - E;
      else if (D == -1) D = E - B - C;
    }
    vector<int> tp{B,C,D,E};
    res.push_back(make_pair(tp, a));
  }
  sort(res.begin(), res.end(), [](const pp &s1, const pp &s2) {
    return s1.first[3] > s2.first[3] || (s1.first[3] == s2.first[3] && COMP(s1.second, s2.second));
  });
  for (auto &p : res) {
    cout << p.second << ' ';
    for (int i = 0; i < 4; i++) {
      if (p.first[i] == -1)
        cout << "? ";
      else
        cout << p.first[i] << ' ';
    }
    cout << endl;
  }
}