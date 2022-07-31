//
// Created by wu on 2022/6/23.
//

#include "leetcode.h"
vector<int> findSubstring(string s, vector<string>& words) {
    int wn = words[0].size(), sn = s.size(), n = words.size(), len = wn*n;
    unordered_map<string,int> diff,dif;
    vector<int> ans;
    for (auto& w : words)
        diff[w]++;
    for (int i = 0; i < wn; i++) {
        dif = diff;
        for (int j = 0; j < n; j++) {
            string tp = s.substr(i + j * wn, wn);
            if (--dif[tp] == 0)
                dif.erase(tp);
        }
        for (int j = i; j +len -1< sn; j+= wn) {
            if (j != i) {
                string tp = s.substr(j-wn,wn);
                if (++dif[tp] == 0)
                    dif.erase(tp);
                tp = s.substr(j + len-wn, wn);
                if (--dif[tp] == 0)
                    dif.erase(tp);
            }
            if (dif.empty())
                ans.push_back(j);
        }
    }
    return ans;
}

int main(void) {
    string s = "wordgoodgoodgoodbestword";
    vector<string> w = {"word","good","best","good"};
    vector<int> tp = findSubstring(s,w);
    for (int i = 0 ; i < tp.size(); i++) cout << tp[i] << ' ';
}