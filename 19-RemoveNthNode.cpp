//
// Created by wu on 2022/2/25.
//

#include<iostream>
#include "string"
#include <cmath>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* nth = new ListNode;
    nth->next = head;
    nth->val = INT_MIN;
    ListNode* tp = head;
    if (n == 1 && head->next == nullptr) return nullptr;
    int i = 1;
    while(tp->next) {
        if (i < n) {
            tp = tp->next;
            i++;
        } else if (i == n) {
            tp = tp->next;
            nth = nth->next;
        }
    }
    if (nth->val == INT_MIN) {
        return nth->next->next;
    }
    else {
        nth->next = nth->next->next;
    }
    return head;
}

void foo(ListNode* tp) {
    while (tp) {
        cout << tp->val << ' ';
        tp = tp->next;
    }
    cout << endl;
}

int main(void) {
    ListNode *nnn = new ListNode;
    ListNode *tp = nnn;
    for (int i = 0; i < 1; i++) {
        tp->val = i + 1;
        tp->next = new ListNode;
        tp = tp->next;
    }
    tp->next = nullptr;
    tp->val = 2;
    foo(nnn);
    tp = removeNthFromEnd(nnn, 2);
    foo(tp);
}