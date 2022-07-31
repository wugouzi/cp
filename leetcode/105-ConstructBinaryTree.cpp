//
// Created by wu on 2022/3/2.
//
#include <vector>

using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) {
        left = nullptr;
        right = nullptr;
        val = k;
    }
};
TreeNode* buildtree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
    if (pl == pr) {
        TreeNode* t = new TreeNode(preorder[pl]);
        return t;
    }
    int k=pl, p;
    int val = preorder[pl];
    TreeNode* t = new TreeNode(val);
    for (p = il; p <= ir; p++)
        if (inorder[p] == val) break;
    if (p > il) {
        for (; k <= pr; k++)
            if (preorder[k] == inorder[p-1])
                break;
        t->left = buildtree(preorder,pl+1,k,inorder,il,p-1);
    }
    if (p < ir) {
        t->right = buildtree(preorder, k+1, pr, inorder, p+1,ir);
    }
    return t;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size() - 1;
    return buildtree(preorder, 0, n, inorder, 0, n);
}

int main(void) {
    vector<int> preorder = {1,2,3}, inorder = {3,2,1};
    TreeNode* tp = buildTree(preorder, inorder);
}