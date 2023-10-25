//
// Created by wu on 2023/10/18.
//
#include "leetcode.h"
class StockPrice {
 public:
  typedef pair<int, int> pp;
  priority_queue<pp> big;
  priority_queue<pp, vector<pp>, greater<pp>> small;
  map<int, int> mm;
  StockPrice() {

  }

  void update(int timestamp, int price) {
    if (!mm.count(timestamp)) {
      big.push(make_pair(price, timestamp));
      small.push(make_pair(price, timestamp));
    }

    mm[timestamp] = price;
  }

  int current() {
    return mm.rbegin()->second;
  }

  int maximum() {
    while (mm[big.top().second] != big.top().first) {
      int t = big.top().second;
      big.pop();
      big.push(make_pair(mm[t], t));
    }
    return big.top().first;
  }

  int minimum() {
    while (mm[small.top().second] != small.top().first) {
      int t = small.top().second;
      small.pop();
      small.push(make_pair(mm[t], t));
    }
    return small.top().first;
  }
};

int main() {
  StockPrice *obj = new StockPrice();
  obj->update(1,10);
  obj->update(2,5);
  cout << obj->current() << endl;
  cout << obj->maximum() << endl;
}