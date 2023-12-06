#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int dif = 1;
  int s = 1;
  while (n--) {
    cout << s << ' ';
    if (m - s - dif >= n) s += dif;
    else s++;
    dif++;
  }
  return 0;
}
// 64 位输出请用 printf("%lld")