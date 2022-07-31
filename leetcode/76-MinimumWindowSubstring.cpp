//
// Created by wu on 2022/2/28.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

/*string minWindow(string s, string t) {
    int ns = s.size(), nt = t.size();
    map<char, int> num;
    int l = -1, r = 0;
    int i = 0, j = 0;
    string ans;
    for (int i = 'a'; i <= 'z'; i++) num[i] = -1;
    for (int i = 'A'; i <= 'Z'; i++) num[i] = -1;
    for (int i = 0; i < nt; i++) num[t[i]] = 0;
    string tp = t;
    while (i < ns && tp != "") {
        size_t found = tp.find(s[i]);
        if (num[s[i]] >= 0) num[s[i]]++;
        if (found != string::npos) {
            tp.erase(found, 1);
            r = i;
            l = l == -1 ? i : l;
            i++;
        } else {
            i++;
        }
    }
    if (tp != "") return "";
    ans = s.substr(l, r - l + 1);
    i = 0;
    char a;
    while (r < s.size()) {
        while(1) {
            if (num[s[l]] == -1) {l++;}
            else {
                num[s[l]]--;
                l++;
                if (num[s[l - 1]] == 0) {
                    if (r - l + 2 < ans.size()) ans = s.substr(l - 1, r - l + 2);
                    break;
                }
            }
        }
        a = s[l - 1];
        while(num[s[l]] == -1) l++;
        r++;
        while (r < s.size() && s[r] != a) {
            if (num[s[r]] != -1) num[s[r]]++;
            r++;
        }
        num[s[r]]++;
        if (r >= s.size()) break;
        if (r - l + 1 < ans.size()) ans = s.substr(l, r - l + 1);
    }
    return ans;
}*/

unordered_map <char, int> ori, cnt;

bool check() {
    for (const auto &p: ori) {
        if (cnt[p.first] < p.second) {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    for (const auto &c: t) {
        ++ori[c];
    }

    int l = 0, r = -1;
    int len = INT_MAX, ansL = -1, ansR = -1;

    while (r < int(s.size())) {
        if (ori.find(s[++r]) != ori.end()) {
            ++cnt[s[r]];
        }
        while (check() && l <= r) {
            if (r - l + 1 < len) {
                len = r - l + 1;
                ansL = l;
            }
            if (ori.find(s[l]) != ori.end()) {
                --cnt[s[l]];
            }
            ++l;
        }
    }

    return ansL == -1 ? string() : s.substr(ansL, len);
}



int main(void) {
    cout << minWindow("ADOBECODEBANC", "ABC");
    //cout << minWindow("bba", "ab");
    //cout << minWindow("a", "aa");
    //cout << minWindow("a", "a");
}
