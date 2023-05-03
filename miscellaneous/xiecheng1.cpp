#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

// N 个数据， k 个桶, k * N / k * log(N/k)=Nlog(N/k)
// 最小堆 N/2logk, Nlog(N/k)+N/2logk
// N + N/2 + N/4 + ...
// N(1-(1/2)^logN)*2 ~ 2N

// p ----------------
// ------ p ---------
// ---k-- p ---------
// ------ p --k -----

int findmedium(string filename, int k, int base) {
  fstream f(filename);
  fstream f1(filename + '0');
  fstream f2(filename + '1');
  int pivot;
  // 暂时找第一个数
  f >> pivot;
  ll count1 = 0;
  ll count2 = 1;
  int a;
  while (f >> a) {
    if (a < pivot) {
      f1 << a;
      count1++;
    } else {
      f2 << a;
      count2++;
    }
  }
  f.close();f1.close();f2.close();
  if (base + count1 == k-1) {
    return a;
  } else if (base + count1 < k-1) {
    return findmedium(filename + '1', k, base + count1);
  } else {
    return findmedium(filename + '0', k, base);
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << findmedium(s, k, 0);
  return 0;
}
