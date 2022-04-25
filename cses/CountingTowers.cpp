//
// Created by wu on 2022/4/22.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, N=1e9+7;
    cin >> n;
    vector<int> nums(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        k = max(nums[i], k);
    }
    vector<long long> sep(k+1), join(k+1);
    sep[1] = 1, join[1] = 1;
    for (int i = 2; i <= k; i++) {
        sep[i] = (4*sep[i-1]+join[i-1])%N;
        join[i] = (sep[i-1]+2*join[i-1])%N;
    }
    for (int i = 0; i < n-1; i++)
        cout << (sep[nums[i]]+join[nums[i]])%N << endl;
    cout << (sep[nums[n-1]]+join[nums[n-1]])%N;
    return 0;
}