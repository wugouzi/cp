//
// Created by wu on 2022/3/9.
//

#ifndef LEETCODE_LEETCODE_H
#define LEETCODE_LEETCODE_H
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <stack>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int k) : val(k), next(nullptr) {};
    ListNode(int k, ListNode* p) : val(k), next(p) {};
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void PreTree(TreeNode* tp) {
    if (!tp) return;
    PreTree(tp->left);
    cout << tp->val << ' ';
    PreTree(tp->right);
    return;
}
#endif //LEETCODE_LEETCODE_H
