#include "leetcode.h"

typedef long long ll;
typedef pair<ll,ll> pp;
int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
  int ans = 0;
  int mod = 1e9+7;
  priority_queue<pp,vector<pp>,greater<pp>> sell;
  priority_queue<pp> buy;
  for (auto &o : orders) {
    if (o[2] == 0) {
      ll am = o[1], pr = o[0];
      while (!sell.empty() && pr >= sell.top().first && am > 0) {
        if (am >= sell.top().second) {
          am -= sell.top().second;
          ans -= sell.top().second;
          sell.pop();
        } else {
          auto tp = sell.top();
          sell.pop();
          tp.second -= am;
          ans = (ans - am + mod) % mod;
          am = 0;
          sell.push(tp);
        }
      }
      if (am > 0) {
        (ans += am) %= mod;
        buy.push({pr, am});
      }
    } else {
      ll am = o[1], pr = o[0];
      while (!buy.empty() && pr <= buy.top().first && am > 0) {
        if (am >= buy.top().second) {
          am -= buy.top().second;
          ans -= buy.top().second;
          buy.pop();
        } else {
          auto tp = buy.top();
          buy.pop();
          tp.second -= am;
          ans = (ans - am + mod) % mod;
          am = 0;
          buy.push(tp);
        }
      }
      if (am > 0) {
        (ans += am) %= mod;
        sell.push({pr, am});
      }
    }
  }
  return ans;
}

int main(void) {
  // vector<vector<int>> tp = {{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}};
  // vector<vector<int>> tp = {{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
  vector<vector<int>> tp = {{26,7,0},{16,1,1},{14,20,0},{23,15,1},{24,26,0},{19,4,1},{1,1,0}};
  cout << getNumberOfBacklogOrders(tp);
}
