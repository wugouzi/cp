//
// Created by wu on 2022/3/11.
//

#include "leetcode.h"

int pa[50];
double w[50];
unordered_map<string,int> ind;
int idx;
int find(int i) {
    int par = i;
    while (par != pa[par]) par = pa[par];
    while (pa[i] != par) {
        w[i] *= w[pa[i]];
        pa[i] = pa[pa[i]];
    }
    return par;
}
void merge(int i, int j, double wei) {
    int x = find(i), y = find(j);
    w[x] = wei;
    pa[x] = y;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for (int i = 0; i < 50; i++) {
        w[i] = 1;
        pa[i] = i;
    }
    for (int i = 0; i < equations.size(); i++) {
        string &s1 = equations[i][0];
        string &s2 = equations[i][1];
        if (!ind.count(s1)) ind[s1] = idx++;
        if (!ind.count(s2)) ind[s2] = idx++;
        merge(ind[s1], ind[s2], values[i]);
    }
    vector<double> ans;
    for (auto &q : queries) {
        string &s1 = q[0];
        string &s2 = q[1];
        if (!ind.count(s1) || !ind.count(s2) || find(ind[s1]) != find(ind[s2]))
            ans.push_back(-1);
        else
            ans.push_back(w[ind[s1]] / w[ind[s2]]);
    }
    return ans;
}

/*
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
}*/
/*

[]

 */




int main(void) {

    vector<vector<string>> eq = {{"x1","x2"},{"x2","x3"},{"x1","x4"},{"x2","x5"}};
    vector<double> values = {3.0,0.5,3.4,5.6};
    vector<vector<string>> queries = {{"x2","x4"},{"x1","x5"},{"x1","x3"},{"x5","x5"},{"x5","x1"},{"x3","x4"},{"x4","x3"},{"x6","x6"},{"x0","x0"}};

    /*
    vector<vector<string>> eq = {{"a","b"},{"e","f"},{"b","e"}};
    vector<double> values = {3.4,1.4,2.3};
    vector<vector<string>> queries = {{"a","f"},{"f","f"},{"e","e"},{"c","c"},{"a","c"},{"f","e"}};
*/
    /*
    vector<vector<string>> eq = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
*/
    vector<double> tp = calcEquation(eq, values, queries);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}