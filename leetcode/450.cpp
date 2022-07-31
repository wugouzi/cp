//
// Created by wu on 2022/6/2.
//

#include "leetcode.h"

bool find;
void del(TreeNode* root, int key) {
    if (!root) return;
    if (find) return;
    if (root->left && root->left->val == key) {
        TreeNode* ll = root->left->left;
        TreeNode* lr = root->left->right;
        if (lr) {
            root->left = lr;
            TreeNode* tp = lr->left;
            if (!tp) {
                lr->left = ll;
            } else {
                while (tp->left) tp = tp->left;
                tp->left = ll;
            }
        } else {
            root->left = ll;
        }
        find = true;
    } else if (root->right && root->right->val == key) {
        TreeNode* rl = root->right->left;
        TreeNode* rr = root->right->right;
        if (rl) {
            root->right = rl;
            TreeNode* tp = rl->right;
            if (!tp) {
                rl->right = rr;
            } else {
                while (tp->right) tp = tp->right;
                tp->right = rr;
            }
        } else {
            root->right = rr;
        }
        find = true;
    }
    deleteNode(root->left,key);
    deleteNode(root->right,key);
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    TreeNode* tp = new TreeNode(1000000);
    find = false;
    tp->left = root;
    del(tp,key);
    return tp->left;
}

int main(void) {
    TreeNode* root = new TreeNode(5);
    TreeNode* tp = new TreeNode(3);
    root->left = tp;

}