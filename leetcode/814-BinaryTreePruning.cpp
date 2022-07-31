//
// Created by wu on 2022/7/23.
//

#include "leetcode.h"

bool t1(TreeNode* root, TreeNode* pa) {
    if (!root) return true;
    bool tp = t1(root->left, root);
    tp = t1(root->right, root) && root->val == 0 && tp;
    //cout << root->val << ' ' << 0+tp << ' ' << pa->val << endl;
    if (tp) {
        if (pa->left == root)
            pa->left = nullptr;
        else
            pa->right = nullptr;
    }
    return tp;
}
TreeNode* pruneTree(TreeNode* root) {
    TreeNode* pa = new TreeNode(-1);
    pa->left = root;
    t1(root, pa);
    return pa->left;
}

int main(void) {
    TreeNode* root = buildtree("1,1,0,1,1,0,1");
    printTree(root);
    cout << endl;
    root = pruneTree(root);
    printTree(root);
}