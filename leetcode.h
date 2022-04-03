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

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int k) : val(k), next(nullptr) {};
    ListNode(int k, ListNode* p) : val(k), next(p) {};
};
#endif //LEETCODE_LEETCODE_H
