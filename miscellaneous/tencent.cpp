#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int ans, k;
int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    int tp;
    while (b) {
        tp = b;
        b = a % b;
        a = tp;
    }
    return a;
}
void brute(vector<int> &nums, int i, int g) {
    if (i == nums.size() && g == k) {
        ans++;
        return;
    }
    brute(nums, i+1, g);
    if (g == -1)
        brute(nums, i+1, nums[i]);
    else {
        brute(nums, i+1, gcd(g, nums[i]));
    }
}
int main(void) {
    int n, a;
    cin >> n >> k;
    vector<int> nums;
    bool has = false;
    for (int i = 0; i < n; i++)  {
        cin >> a;
        if (a % k == 0)
            nums.push_back(a);
    }
    brute(nums, 0, -1);
    cout << ans;
    return 0;
}