//
// Created by wu on 2022/3/20.
//

#include "leetcode.h"

unordered_map<int, int> pa;
unordered_map<int, int> size;
string s;
int find(int i) {
    while (pa[i] != i) {
        int tp = pa[i];
        pa[i] = pa[pa[i]];
        i = tp;
    }
    return i;
}
void merge(int i, int j) {
    int p1 = find(i), p2 = find(j);
    size[p1] += size[p2];
    pa[p2] = p1;
}
void init (int i) {
    pa[i] = i;
    size[i] = 1;
}

vector<int> longestRepeating(string s, string Ch, vector<int>& In) {
    int n = s.size();
    int ans = 0;
    init(0);
    for (int i = 1; i < n; i++) {
        init(i);
        if (s[i] == s[i-1]) {
            merge(i, i-1);
            ans = max(size[find(i)], ans);
        }
    }
    vector<int> anss;
    for (int i = 0; i < Ch.size(); i++) {
        int j = In[i];
        int ch = Ch[i];
        if (s[j] != ch) {
            size[find(j)]--;
            s[j] = ch;
            init(j);
            if (j >= 0 && s[j-1] == ch) {
                merge(j, j-1);
            }
            if (j < n && s[j+1] == s[j]) {
                merge(j, j+1);
            }
            ans = max(size[find(j)], ans);
        }
        anss.push_back(ans);
    }
    return anss;
}

int main(void) {
    string s = "dbgmcagale";
    string q = "mf";
    vector<int> ind = {5,0};
    vector<int> tp = longestRepeating(s, q, ind);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}