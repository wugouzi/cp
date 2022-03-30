//
// Created by wu on 2022/3/11.
//
#include "leetcode.h"

unordered_map<char, char> parent;
unordered_map<char, int> size;
char find(char x) {
    char pa = x;
    if (parent[pa] != pa) {
        pa = parent[pa];
    }
    if (parent[x] != x) {
        char tp = parent[x];
        parent[x] = pa;
        x = tp;
    }
    return pa;
}

void merge(char x, char y) {
    char r1 = find(x), r2 = find(y);
    if (r1 == r2) return;
    if (size[r1] < size[r2]) {
        char tp = r2; r2 = r1; r1 = tp;
    }
    size[r1] += size[r2];
    parent[r2] = r1;
}
void makeset(char s) {
    if (parent.find(s) == parent.end()) {
        parent[s] = s;
        size[s] = 1;
    }
}
bool equationsPossible(vector<string>& equations) {
    vector<string> s;
    for (auto& c : equations) {
        if (c[1] == '!') s.push_back(c);
        else {
            char c1 = c[0], c2 = c[3];
            makeset(c1);
            makeset(c2);
            merge(c1, c2);
        }
    }

    for (auto& c : s) {
        if (find(c[0]) == find(c[3])) return false;
    }
    return true;
}

int main(void) {
    vector<string> q = {"a==b", "a!=b"};
    cout << equationsPossible(q);
}