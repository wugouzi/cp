//
// Created by wu on 2022/4/11.
//

#include "leetcode.h"

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    stack<int> s;
    TreeNode* t = new TreeNode(nums[0]), *head = t;
    unordered_map<int, TreeNode*> mp;
    s.push(nums[0]);
    mp[nums[0]] = t;
    for (int i = 1; i < nums.size(); i++) {
        TreeNode *tp = new TreeNode(nums[i]), *tpp=nullptr;
        mp[nums[i]] = tp;
        while (!s.empty() && s.top() < nums[i]) {
            tpp = mp[s.top()];
            s.pop();
        }
        tp->left = tpp;
        if (!s.empty()) {
            mp[s.top()]->right = tp;
        } else {
            head = tp;
        }
        s.push(nums[i]);
    }
    return head;
}

int main(void) {
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* tp = constructMaximumBinaryTree(nums);
    PreTree(tp);
}