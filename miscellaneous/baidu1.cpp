#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  k++;
  int p = 1;
  while (k--) {
    while (true) {
      p++;
      bool isp = true;
      for (int j = 2; j * j <= p; j++)
        if (p % j == 0) {
          isp = false;
          break;
        }
      if (isp) {
        if (p > n) {
          cout << n;
          return 0;
        }
        break;
      }
    }
  }
  cout << p - 1;
  return 0;
}
// 64 位输出请用 printf("%lld")