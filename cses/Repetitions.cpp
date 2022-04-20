//
// Created by wu on 2022/4/20.
//

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    char last=s[0];
    int ans=1;
    int cur=1;
    for (unsigned int i = 1; i < s.size(); i++) {
        if (s[i] == last)
            cur++;
        else {
            last = s[i];
            cur = 1;
        }
        ans = max(cur, ans);
    }
    cout << ans;
    return 0;
}