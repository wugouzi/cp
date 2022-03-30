/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void handle(ListNode* tp, bool carry) {
        ListNode* last;
        while (carry && tp) {
            carry = tp->val == 9 ? true : false;
            tp->val = tp->val == 9 ? 0 : tp->val + 1;
            last = tp;
            tp = tp->next;
        }
        if (carry) {
            last->next = new ListNode(1);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* last;
        ListNode* head = l1;
        while (l1 && l2) {
            int val = l1->val + l2->val + (carry ? 1 : 0);
            carry = val > 9 ? true : false;
            l1->val = val % 10;
            last = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) {
            last->next = l2;
            handle(l2, carry);
        }
        else if (l1) {
            handle(l1, carry);
        } else if (carry) {
            last->next = new ListNode(1);
        }
        return head;
    }
};
// @lc code=end

