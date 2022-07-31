//
// Created by wu on 2022/3/5.
//
#include <vector>
#include <iostream>
using namespace  std;

int mmap(vector<int>& mapping, int num) {
    if (num < 10) return mapping[num];
    return mmap(mapping, num/10) * 10 + mapping[num%10];
}
int cus(vector<int>& mapping, vector<int>& nums, int i, int j) {
    int t1 = mmap(mapping, nums[i]);
    int t2 = mmap(mapping, nums[j]);
    if (t1 < t2 || (t1 == t2 && i < j)) return true;
    return false;
}
void swap(vector<int>& nums, int i, int j) {
    int tp = nums[i];
    nums[i] = nums[j];
    nums[j] = tp;
}
int partition(vector<int>& mapping, vector<int>& nums, int l, int r) {
    int i = l-1;
    for (int j = l; j < r; j++)
        if (cus(mapping, nums, j, r))
            swap(nums, ++i, j);
    swap(nums, ++i, r);
    return i;
}
void quick(vector<int>& mapping, vector<int>& nums, int l, int r) {
    if (l >= r || l < 0 || r >= nums.size() || l >= nums.size() || r < 0)
        return;
    int p = partition(mapping, nums, l, r);
    quick(mapping, nums, l, p-1);
    quick(mapping, nums, p+1,r);
}
vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    quick(mapping, nums,0,nums.size()-1);
    return nums;
}

int main(void) {
    //vector<int> mapping = {8,9,4,0,2,1,3,5,7,6}, nums = {991,338,38};
    vector<int> mapping = {0,1,2,3,4,5,6,7,8,9}, nums = {0,1,2,3,4,5,6,7,8,9};
    vector<int> tp = sortJumbled(mapping, nums);
    for (int i = 0; i < tp.size(); i++)
        cout << tp[i] << ' ';

}