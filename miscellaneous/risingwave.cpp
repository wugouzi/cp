#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

class RESP {
public:
  vector<RESP> resps_;
  string s_;
  int val_;
  int type_; // 1 for simple, 2 for error, 3 for bulk, 0 for int

  int len(string &s, int i) {
    if (s[i] == '*') {
      int n = 0, j = i + 1;
      while (j < s.size() && s[j] != '\r') {
        n = n * 10 + s[j] - '0';
        j++;
      }
      j += 2;
      while (n--) {
        while (j < s.size() && s[j] != '\n') j++;
        j++;
      }
      return j - i;
    }
    if (s[i] == '$') {
      int j = i + 1;
      while (j < s.size() && s[j] != '\n') j++;
      j++;
      while (j < s.size() && s[j] != '\n') j++;
      j++;
      return j - i;
    }
    int j = i + 1;
    while (j < s.size() && s[j] != '\n') j++;
    return j - i + 1;
  }

  RESP(string s) {
    type_ = 0;
    if (s[0] == '*') {
      int n = 0, i = 1;
      for (; s[i] != '\r'; i++)
        n = n * 10 + s[i] - '0';
      i += 2;
      while (n--) {
        int l = len(s, i);
        resps_.push_back(RESP(s.substr(i, l)));
        i += l;
      }
    } else if (s[0] == ':') {
      int n = 0, i = 1;
      for (; s[i] != '\r'; i++)
        n = n * 10 + s[i] - '0';
      val_ = n;
    } else if (s[0] == '$') {
      type_ = 3;
      int n = 0, i = 1;
      while (i < s.size() && s[i] != '\r') {
        n = n * 10 + s[i] - '0';
        i++;
      }
      i += 2;
      s_ = s.substr(i, n);
    } else {
      if (s[0] == '+') type_ = 1;
      else if (s[0] == '-') type_ = 2;
      s_ = s.substr(1, s.size() - 4);
    }
  }

  void print() {
    if (resps_.size() > 0) {
      cout << "[";
      for (auto &r : resps_) {
        r.print();
      }
      cout << "]";
    } else if (type_ == 0) {
      cout << "INT: " << val_ << ",";
    } else if (type_ == 1) {
      cout << "SIMPLE: " << s_ << ",";
    } else if (type_ == 2) {
      cout << "ERROR: " << s_ << ",";
    } else if (type_ == 3) {
      cout << "BULK: " << s_ << ",";
    }
  }
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (cin >> s) {
    RESP test(s);
    test.print();
  }
  return 0;
}


/*
+balabalbala\r\n
$6\r\nbalala\r\n
*3\r\n$1\r\na\r\n$2\r\nbb\r\n$3\r\nccc\r\n
*3\r\n*2\r\n+str\r\n$10\r\nbulk_bytes\r\n+str_1\r\n$12\r\nbulk_bytes_1\r\n
*/
