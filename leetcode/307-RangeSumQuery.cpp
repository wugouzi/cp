//
// Created by wu on 2022/3/30.
//

#include "leetcode.h"

class NumArray {
public:
    vector<int> tree;
    vector<int> ori;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.resize(n+1);
        ori = nums;
        for (int i = 1; i <= n; i++) {
            tree[i] = nums[i-1];
            for (int j = i-(i&-i)+1; j < i; j++)
                tree[i] += nums[j-1];
        }
    }

    int sum(int i) {
        if (i < 0) return 0;
        i++;
        int sum = 0;
        while (i >= 1) {
            sum += tree[i];
            i -= i&-i;
        }
        return sum;
    }

    void update(int index, int val) {
        int diff = ori[index] - val;
        int i = index+1;
        ori[index] = val;
        while (i < tree.size()) {
            tree[i] -= diff;
            i += (-i&i);
        }
        return;
    }

    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};
//["NumArray","update","update","update","sumRange","update","sumRange","update","sumRange","sumRange","update"]
//[[[7,2,7,2,0]],[4,6],[0,2],[0,9],[4,4],[3,8],[0,4],[4,1],[0,3],[0,4],[0,4]]
int main(void) {
    vector<int> tp = {7,2,7,2,0};
    NumArray numArray(tp);
    numArray.update(4,6);
    numArray.update(0,2);
    numArray.update(0, 9);
    cout << numArray.sumRange(4,4) << ' ';
    numArray.update(3, 8);
    cout << numArray.sumRange(0,4) << ' ';
    numArray.update(4, 1);
    cout << numArray.sumRange(0,3) << ' ';
    cout << numArray.sumRange(0,4) << ' ';

}

