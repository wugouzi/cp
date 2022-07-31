//
// Created by wu on 2022/2/27.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271};
vector<vector<int>> perm(vector<int>&nums, long long used) {
    vector<vector<int>> ans;
    for (auto i : nums) {
        if (used % primes[i + 10]) {
            vector<vector<int>> tp = perm(nums, used * primes[i + 10]);
            for (auto&& j : tp) {
                j.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}
vector<vector<int>> permute(vector<int>& nums) {
    return perm(nums, 1);
}

int main(void) {
    vector<int> tp = {1,2,3};
    permute(tp);
}