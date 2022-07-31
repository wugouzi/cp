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
#include <climits>
#include <cfloat>
#include <cctype>
#include <locale>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <sstream>

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

TreeNode* _buildtree(TreeNode* root, vector<long long> list, int i) {
    if (i*2 < list.size() && list[i*2] != LLONG_MAX) {
        root->left = new TreeNode(list[i*2]);
        _buildtree(root->left, list, i*2);
    }
    if (i*2+1 < list.size() && list[i*2+1] != LLONG_MAX) {
        root->right = new TreeNode(list[i*2+1]);
        _buildtree(root->right, list, i*2+1);
    }
    return root;
}

TreeNode* buildtree(string s) {
    vector<long long> tp(1,0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int tmp = s[i++]-'0';
            while (s[i] >= '0' && s[i] <= '9') {
                tmp = tmp*10+s[i]-'0';
                i++;
            }
            tp.push_back(tmp);
        } else if (s[i] == 'n') {
            i += 4;
            tp.push_back(LLONG_MAX);
        }
    }
    TreeNode* root = new TreeNode(tp[1]);
    _buildtree(root, tp, 1);
    return root;
}

void printTree(TreeNode* p) {
    if (p) {
        cout << p->val << ' ';
        printTree(p->left);
        printTree(p->right);
    }
}

void PreTree(TreeNode* tp) {
    if (!tp) return;
    PreTree(tp->left);
    cout << tp->val << ' ';
    PreTree(tp->right);
    return;
}

#endif //LEETCODE_LEETCODE_H
