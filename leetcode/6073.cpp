//
// Created by wu on 2022/4/17.
//

#include "leetcode.h"

int ans;
int dfs(vector<int>& pa, vector<vector<int>>& ch, string& s, int node) {
    int cnt = 0;
    int max1 = 0, max2 = 0;
    for (auto& l : ch[node]) {
        bool dif = s[l] != s[node];
        int tp = dfs(pa, ch, s, l);
        if (dif && tp > max1) {
            max2 = max1;
            max1 = tp;
        } else if (dif && tp > max2)
            max2 = tp;
    }
    ans = max(ans, max1+max2+1);
    return max1+1;
}
int longestPath(vector<int>& parent, string& s) {
    int n = parent.size();
    ans = 0;
    vector<vector<int>> child(n);
    int p;
    for (int i = 0; i < n; i++)
        if (parent[i] != -1)
            child[parent[i]].push_back(i);
        else
            p = i;
    dfs(parent, child, s, p);
    return ans;
}


int main(void) {
    vector<int> p = {-1,137,65,60,73,138,81,17,45,163,145,99,29,162,19,20,132,132,13,60,21,18,155,65,13,163,125,102,96,60,50,101,100,86,162,42,162,94,21,56,45,56,13,23,101,76,57,89,4,161,16,139,29,60,44,127,19,68,71,55,13,36,148,129,75,41,107,91,52,42,93,85,125,89,132,13,141,21,152,21,79,160,130,103,46,65,71,33,129,0,19,148,65,125,41,38,104,115,130,164,138,108,65,31,13,60,29,116,26,58,118,10,138,14,28,91,60,47,2,149,99,28,154,71,96,60,106,79,129,83,42,102,34,41,55,31,154,26,34,127,42,133,113,125,113,13,54,132,13,56,13,42,102,135,130,75,25,80,159,39,29,41,89,85,19};
    string s = "ajunvefrdrpgxltugqqrwisyfwwtldxjgaxsbbkhvuqeoigqssefoyngykgtthpzvsxgxrqedntvsjcpdnupvqtroxmbpsdwoswxfarnixkvcimzgvrevxnxtkkovwxcjmtgqrrsqyshxbfxptuvqrytctujnzzydhpal";
    cout << longestPath(p, s);
}