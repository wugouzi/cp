//
// Created by wu on 2022/3/6.
//
#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    map<int, TreeNode*> s;
    unordered_set<TreeNode*> heads;
    for (auto&& d : descriptions) {
        int pa = d[0];
        int ch = d[1];
        TreeNode *p, *c;
        if (s.find(pa) == s.end()) {
            p = new TreeNode(pa);
            heads.insert(p);
            s[pa] = p;
        } else p = s[pa];
        if (s.find(ch) == s.end()) {
            c = new TreeNode(ch);
            s[ch] = c;
        }
        else {
            c = s[ch];
            heads.erase(c);
        }
        if (d[2]) p->left = c;
        else p->right = c;
    }
    return *heads.begin();
}

int main(void) {
    vector<vector<int>> des = {{1,2,1},{2,3,0},{3,4,1}};
    TreeNode* tp = createBinaryTree(des);
}