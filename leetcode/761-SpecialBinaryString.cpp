//
// Created by wu on 2022/8/8.
//

#include "leetcode.h"

string makeLargestSpecial(string s) {
    if (s.size() == 0) return s;
    vector<string> tmp;
    for (int i = 0; i < s.size(); i++) {
        int cnt = 1, j = i + 1;
        while (cnt) {
            if (s[j] == '1')
                cnt++;
            else
                cnt--;
            j++;
        }
        tmp.push_back(s.substr(i, j-i));
        i = j-1;
    }
    if (tmp.size() == 1) {
        return "1"+makeLargestSpecial(s.substr(1, s.size()-2))+"0";
    }
    for (auto& s : tmp)
        s = makeLargestSpecial(s);
    sort(tmp.begin(), tmp.end(), [](const auto& s1, const auto& s2) {
        return s1.compare(s2) > 0;
    });
    string ans;
    for (auto& s : tmp)
        ans += s;
    return ans;
}

int main(void){
    string s1 = "11";
    cout << 0+(s1.compare("10001")) << endl;
    cout << makeLargestSpecial("11011000");
}