//
// Created by wu on 2022/5/11.
//

#include "leetcode.h"

string serialize(TreeNode* root) {
    if (!root) return "()";
    return "("+serialize(root->left)+to_string(root->val)+serialize(root->right)+")";
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.size() == 2 || data.size() == 0) return nullptr;
    int i = 1;
    int cnt = 0;
    while (data[i] < '0' || data[i] > '9' || cnt != 0) {
        if (data[i] == '(') cnt++;
        else if (data[i] == ')') cnt--;
        i++;
    }
    TreeNode* l = deserialize(data.substr(1,i-1));
    int j = i;
    while (data[i] != '(') i++;
    TreeNode* t = new TreeNode(stoi(data.substr(j, i-j)));
    t->left = l;
    t->right = deserialize(data.substr(i,data.size()-i-1));
    return t;
}

int main(void) {
    TreeNode* tp = deserialize("((()300())300(()300()))");
    string a = serialize(tp);
    tp = deserialize(a);
    printTree(tp);
}