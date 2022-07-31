//
// Created by wu on 2022/4/3.
//

#include "leetcode.h"

vector<vector<int>> edge;
string bword;
bool check(string c1, string c2) {
    int n1 = c1.size(), n2 = c2.size();
    if (n1 != n2)
        return false;
    int diff = 0;
    for (int i = 0; i < n1; i++) {
        if (c1[i] != c2[i] && !diff)
            diff++;
        else if (c1[i] != c2[i] && diff)
            return false;
    }
    return true;
}
void add(vector<string>& wordList, int i) {
    if (check(bword, wordList[i]))
        edge[wordList.size()].push_back(i);
    for (int j = 0; j < i; j++)
        if (check(wordList[j], wordList[i])) {
            edge[j].push_back(i);
            edge[i].push_back(j);
        }
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();
    bword = beginWord;
    edge.resize(n+1);
    int end = -1;
    for (int i = 0; i < n; i++) {
        add(wordList, i);
        if (wordList[i] == endWord)
            end = i;
    }
    if (end == -1)
        return 0;
    queue<int> q;
    q.push(n);
    vector<int> dist(n+1);
    dist[n]=1;
    while (!q.empty()) {
        int src = q.front();
        q.pop();
        for (int i = 0; i < edge[src].size(); i++) {
            int tar = edge[src][i];
            if (!dist[tar]) {
                dist[tar] = dist[src]+1;
                q.push(tar);
            }
            if (tar == end)
                return dist[tar];
        }
    }
    return 0;
}

int main(void) {
    vector<string> list = {"hot","dot","dog","lot","log","cog"};
    string bword = "hit";
    string eword = "cog";
    cout << ladderLength(bword, eword, list);
}