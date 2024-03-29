//
// Created by wu on 2022/3/4.
//
#include "leetcode.h"

class LRUCache {
public:
    class Node {
    public:
        int k;
        int v;
        Node *next;
        Node *prev;
        Node(int kk, int vv) : k(kk), v(vv), next(nullptr), prev(nullptr) {}
        Node(int kk, int vv, Node *hh, Node *tt) : k(kk), v(vv), next(hh), prev(tt) {}
    };
    Node *head, *tail;
    int sz;
    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-2,-2,nullptr,head);
        head->next = tail;
        sz = 0;
        cap = capacity;
    }
    void p() {
        Node *tp = head->next;
        while (tp->v > -1) {
            cout << tp->k << ' ';
            tp = tp->next;
        }
        cout << '\n';
    }

    int get(int key) {
        if (mp.count(key)) {
            Node *tp = mp[key];
            tp->prev->next = tp->next;
            tp->next->prev = tp->prev;
            tp->prev = head;
            tp->next = head->next;
            head->next->prev = tp;
            head->next = tp;
            p();
            return tp->v;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->v = value;
            return;
        }
        if (sz == cap) {
            Node *tp = tail->prev->prev;
            int k = tail->prev->k;
            tail->prev = tp;
            delete tp->next;
            tp->next = tail;
            mp.erase(k);
            sz--;
        }
        Node *tp = new Node(key,value,head->next,head);
        head->next->prev = tp;
        head->next = tp;
        mp[key] = tp;
        sz++;
        p();
    }
};

/*
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
};*/
//["LRUCache","put","put","get","put","put","get"]
//[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
int main(void) {
    LRUCache lru(2);
    lru.put(1,1);
    lru.put(2,2);
    cout << lru.get(1) << endl;
    lru.put(3,3);
    cout << lru.get(2) << endl;
    lru.put(4,4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;

    /*
    LRUCache lru(2);
    lru.put(2,1);
    lru.put(2,2);
    cout << lru.get(2) << endl;
    lru.put(1,1);
    lru.put(4,1);
    cout << lru.get(2) << endl;
     */
}