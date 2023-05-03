#include <iostream>
#include <vector>
using namespace std;
using pp = pair<int,int>;
pp convert(int x) {
    switch(x) {
        case -8: return make_pair(3,-1);
        case -4: return make_pair(2,-1);
        case -2: return make_pair(1,-1);
        case -1: return make_pair(0,-1);
        case 1: return make_pair(0,1);
        case 2: return make_pair(1,1);
        case 4: return make_pair(2,1);
        case 8: return make_pair(3,1);
    }
    return make_pair(0,3);
}
pp add(pp t1, pp t2) {
    return make_pair(t1.first + t2.first, t1.second * t2.second);
}
pp divide(pp t1, pp t2) {
    return make_pair(t1.first - t2.first, t1.second * t2.second);
}
int ans, L, R;
void update(vector<pp> &pre, int l) {
    int n = pre.size();
    for (int i = 0; i < n; i++) {
        if (pre[i].first * pre[i].second > ans) {
            ans = pre[i].first;
            L = l;
            R = l + i;
        }
        for (int j = 0; j < i; j++) {
            pp tp = divide(pre[i], pre[j]);
            if (tp.first * tp.second > ans) {
                ans = tp.first;
                L = j + 1;
                R = i;
            }
        }
    }
}


int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int left = 0, right = 0;
    vector<pp> pre(n);
    while (nums[left] == 0) left++;
    right = left;
    int ans = 0, l = -1, r = -1;
    while (right < n) {
        while (right < n && nums[right] != 0) right++;
        pre[0] = convert(nums[left]);
        for (int i = 1; i + left < right; i++) {
            pre[i] = add(pre[i-1], convert(nums[i+left]));
        }
        update(pre, left);
        left = right;
        while (left < n && nums[left] == 0) left++;
        right = left;
    }
    cout << L << ' ' << R;
}

/*
8
0 2 0 -2 8 -1 0 0
 */