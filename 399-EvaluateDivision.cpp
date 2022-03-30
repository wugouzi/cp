//
// Created by wu on 2022/3/11.
//

#include "leetcode.h"

map<string, string> parent;
map<string, double> weight;
void init(string i) {
    if (!weight[i]) {
        parent[i] = i;
        weight[i] = 1;
    }
}

string find(string i) {
    string pa = i;
    while (parent[pa] != pa) pa = parent[pa];
    while (i != pa && pa != parent[i]) {
        weight[i] *= weight[parent[i]];
        parent[i] = parent[parent[i]];
    }
    return pa;
}

void merge(string i, string j, double w) {
    string t1 = find(i), t2 = find(j);
    weight[t1] = w * weight[j] / weight[i];
    parent[t1] = t2;
}
double calc(string i, string j) {
    if (weight[j] == 0) return -1;
    string t1 = find(i), t2 = find(j);
    if (t1 != t2) return -1;
    return weight[i] / weight[j];
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for (int i = 0; i < equations.size(); i++) {
        string s1 = equations[i][0], s2 = equations[i][1];
        init(s1);
        init(s2);
        merge(s1, s2, values[i]);
    }
    vector<double> ans;
    for (auto& c : queries) {
        ans.push_back(calc(c[0], c[1]));
    }
    return ans;
}

int main(void) {
    vector<vector<string>> eq = {{"a","b"},{"e","f"},{"b","e"}};
    vector<double> values = {3.4,1.4,2.3};
    vector<vector<string>> queries = {{"b","a"},{"a","f"},{"f","f"},{"e","e"},{"c","c"},{"a","c"},{"f","e"}};
    vector<double> tp = calcEquation(eq, values, queries);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}