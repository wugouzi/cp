//
// Created by wu on 2022/3/4.
//
#include <iostream>
#include <queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* merge(ListNode* t1, ListNode* t2) {
    ListNode *head = new ListNode(), *tp = head;
    while(t1 && t2) {
        if (t1->val < t2->val) {
            tp->next = t1;
            t1 = t1->next;
            tp = tp->next;
        } else {
            tp->next = t2;
            t2 = t2->next;
            tp = tp->next;
        }
    }
    if (t1) tp->next = t1;
    if (t2) tp->next = t2;
    return head->next;
}
ListNode* sortList(ListNode* head) {
    if (!head) return head;
    queue<ListNode*> nodes;
    ListNode* tp = head;
    while(tp) {
        ListNode* tpp = tp;
        tp = tp->next;
        tpp->next = nullptr;
        nodes.push(tpp);
    }
    while(nodes.size() > 1) {
        ListNode* t1 = nodes.front();
        nodes.pop();
        ListNode* t2 = nodes.front();
        nodes.pop();
        nodes.push(merge(t1, t2));
    }
    return nodes.front();
}

int main(void) {
    vector<int> tp = {-1,5,3,4,0};
    ListNode *head = new ListNode();
    ListNode *heads = head;
    for (int i = 0; i < tp.size(); i++) {
        heads->next = new ListNode(tp[i]);
        heads = heads->next;
    }
    head = sortList(head->next);
    while(head) {
        cout << head->val << ' ';
        head = head->next;
    }
}