//
// Created by wu on 2022/3/16.
//

#include "leetcode.h"
class AllOne {
public:
    struct Node {
        int val;
        string s;
        Node *next;
        Node *prev;

        Node(int k, string ss) : val(k), s(ss), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;
    unordered_map<string, Node *> mp;
    string mas, mis;

    void concat(Node *t1, Node *t2) {
        t1->next = t2;
        t2->prev = t1;
    }

    void exch(Node *t1, Node *t2) {
        Node *tp11 = t1->prev, *tp12 = t1->next, *tp21 = t2->prev, *tp22 = t2->next;
        if (t1->next == t2) {
            concat(tp11, t2);
            concat(t2, t1);
            concat(t1, tp22);
        } else if (t1->prev == t2) {
            concat(tp21, t1);
            concat(t1, t2);
            concat(t2, tp12);
        } else if (t1 == t2) return;
        else {
            concat(tp11, t2);
            concat(t2, tp12);
            concat(tp21, t1);
            concat(t1, tp22);
        }
    }

    AllOne() {
        head = new Node(INT_MAX / 2, "");
        tail = new Node(INT_MIN / 2, "");
        concat(head, tail);
    }

    void print() {
        Node *tp = head;
        while (tp) {
            cout << tp->s << ':' << tp->val << "| ";
            tp = tp->next;
        }
        cout << endl;
    }

    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            mp[key] = new Node(1, key);
            Node *tp = tail->prev;
            concat(tp, mp[key]);
            concat(mp[key], tail);
        } else {
            mp[key]->val++;
            Node *tp = mp[key];
            while (tp->prev->val < mp[key]->val) {
                tp = tp->prev;
            }
            exch(tp, mp[key]);
        }
        print();
    }

    void dec(string key) {
        if (mp[key]->val == 1) {
            Node *tp1 = mp[key]->prev, *tp2 = mp[key]->next;
            concat(tp1, tp2);
            free(mp[key]);
            mp.erase(key);
        } else {
            mp[key]->val--;
            Node *tp = mp[key];
            while (tp->next->val > mp[key]->val) tp = tp->next;
            exch(tp, mp[key]);
        }
    }

    string getMaxKey() {
        return head->next->s;
    }

    string getMinKey() {
        return tail->prev->s;
    }
};

int main(void) {
    AllOne allOne;
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("c");
    allOne.inc("d");
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("c");
    allOne.inc("d");
    allOne.inc("c");
    allOne.inc("d");allOne.inc("d");allOne.inc("a");
    cout << allOne.getMinKey();

}