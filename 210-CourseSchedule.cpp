//
// Created by wu on 2022/3/5.
//
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
vector<vector<int>> E;
stack<int> s;
vector<int> visited;
bool find(int i) {
    visited[i] = 1;
    for (int& j : E[i]) {
        if (visited[j] == 1)
            return false;
        if (visited[j] == 2)
            continue;
        if (!find(j)) return false;
    }
    visited[i] = 2;
    s.push(i);
    return true;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    E.resize(numCourses);
    visited.resize(numCourses);
    vector<int> ans;
    bool flag = true;
    for (vector<int>& i : prerequisites)
        E[i[1]].push_back(i[0]);
    for (int i = 0; i < numCourses; i++)
        if (visited[i] == 0)
            if (!find(i)) return ans;

    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main(void) {
    //int n = 4;
    //vector<vector<int>> pre = {{1,0},{2,0},{3,1},{3,2}};
    int n = 2;
    vector<vector<int>> pre = {{0,1},{1,0}};
    vector<int> a = findOrder(n, pre);
    for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
}