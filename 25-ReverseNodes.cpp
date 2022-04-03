//
// Created by wu on 2022/4/2.
//

#include "leetcode.h"

ListNode* reverseKGroup(ListNode* head, int k) {
    int cnt = 0;
    ListNode* tp = head;
    stack<ListNode*> s;
    ListNode* ans = new ListNode();
    ListNode* newtp = ans;
    ListNode* ntp=head;
    while (tp) {
        if (cnt < k) {
            s.push(tp);
            cnt++;
        } else {
            while (!s.empty()) {
                newtp->next = s.top();
                s.pop();
                newtp = newtp->next;
            }
            cnt = 1;
            s.push(tp);
            ntp = tp;
        }
        tp = tp->next;
    }
    if (cnt == k) {
        while (!s.empty()) {
            newtp->next = s.top();
            s.pop();
            newtp = newtp->next;
        }
        newtp->next = nullptr;
    }
    else if (cnt)
        newtp->next = ntp;
    return ans->next;
}

int main(void) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode* tp = reverseKGroup(head, 2);
}