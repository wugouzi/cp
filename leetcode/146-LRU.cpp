//
// Created by wu on 2022/3/4.
//
#include <map>
#include <iostream>

using namespace std;
struct List {
    List *prev;
    List *next;
    int val;
    int key;
    List(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {};
    List() : key(0), val(0), prev(nullptr), next(nullptr) {};
};
class LRUCache {
public:
    int capacity;
    int cur;
    map<int, List*> s;
    List* head;
    List* tail;
    LRUCache(int capa) {
        capacity = capa;
        cur = 0;
        head = new List();
        tail = new List();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (s.find(key) != s.end()) {
            front(s[key]);
            return s[key]->val;
        }
        return -1;
    }

    void front(List* tp) {
        tp->prev->next = tp->next;
        tp->next->prev = tp->prev;
        tp->next = head->next;
        tp->prev = head;
        head->next->prev = tp;
        head->next = tp;
    }

    void put(int key, int value) {
        if (s.find(key) != s.end()) {
            s[key]->val = value;
            front(s[key]);
        } else {
            cur++;
            if (cur > capacity) {
                List* tp = tail->prev;
                tp->prev->next = tail;
                tail->prev = tp->prev;
                s.erase(s.find(tp->key));
                cur--;
                delete tp;
            }
            List *tp = new List(key, value);
            tp->next = head->next;
            tp->prev = head;
            head->next->prev = tp;
            head->next = tp;
            s[key] = tp;
        }

    }
};
//["LRUCache","put","put","get","put","put","get"]
//[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
int main(void) {
    LRUCache lru(2);
    lru.put(2,1);
    lru.put(2,2);
    cout << lru.get(2) << endl;
    lru.put(1,1);
    lru.put(4,1);
    cout << lru.get(2) << endl;
}