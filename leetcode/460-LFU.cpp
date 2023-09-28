#include "leetcode.h"

class LFUCache {
public:
    class Node {
        public:
            int k;
            int v;
            int cnt;
            Node(int _k, int _v): k(_k), v(_v), cnt(1) {}
    };
    unordered_map<int, list<Node *>> freq;
    unordered_map<int, list<Node *>::iterator> key_map;
    int size = 0;
    int minfreq = INT_MAX;
    LFUCache(int capacity) {
        size = capacity;
    }

    int add(int key) {
        auto iter = key_map[key];
        auto node = *iter;
        node->cnt++;
        int ans = node->v;
        int cnt = node->cnt;
        freq[cnt].push_front(node);
        key_map[key] = freq[cnt].begin();
        if (freq[cnt - 1].size() == 1) {
            if (minfreq == cnt - 1) minfreq = cnt;
            freq.erase(cnt - 1);
        } else {
            freq[cnt - 1].erase(iter);
        }
        return ans;
    }

    int get(int key) {
        if (key_map.count(key)) {
            return add(key);
        }
        return -1;
    }

    void put(int key, int value) {
        if (key_map.count(key)) {
            auto iter = key_map[key];
            (*iter)->v = value;
            add(key);
            return;
        }
        if (key_map.size() == size) {
            auto node = freq[minfreq].back();
            key_map.erase(node->k);
            freq[minfreq].pop_back();
            if (freq[minfreq].empty())
                freq.erase(minfreq);
            delete node;
        }
        Node *tp = new Node(key, value);
        freq[1].push_front(tp);
        key_map[key] = freq[1].begin();
        minfreq = 1;
    }
};
// [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
int main(void) {
  LFUCache lfu(2);
  cout << lfu.get(2);
  lfu.put(2,6);
  cout << lfu.get(1);
  lfu.put(1,5);
  lfu.put(1,2);
  lfu.get(1);
  lfu.get(2);
  // lfu.put(3,1);
  // lfu.put(2,1);
  // lfu.put(2,2);
  // lfu.put(4,4);
  // cout << lfu.get(2) << endl;
  // lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
  // lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
  // cout << lfu.get(1);      // 返回 1
  // // cache=[1,2], cnt(2)=1, cnt(1)=2
  // lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
  // // cache=[3,1], cnt(3)=1, cnt(1)=2
  // cout << lfu.get(2);      // 返回 -1（未找到）
  // cout << lfu.get(3);      // 返回 3
  // // cache=[3,1], cnt(3)=2, cnt(1)=2
  // lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
  // // cache=[4,3], cnt(4)=1, cnt(3)=2
  // cout << lfu.get(1);      // 返回 -1（未找到）
  // cout << lfu.get(3);      // 返回 3
  // // cache=[3,4], cnt(4)=1, cnt(3)=3
  // cout << lfu.get(4);      // 返回 4
  // // cache=[3,4], cnt(4)=2, cnt(3)=3
}
