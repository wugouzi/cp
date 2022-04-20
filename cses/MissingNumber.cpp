//
// Created by wu on 2022/4/20.
//

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n,m;
    cin >> n;
    vector<bool> tp(n);
    for (int i = 0; i < n-1; i++) {
        cin >> m;
        tp[m-1]=true;
    }
    for (int i = 0; i < n; i++)
        if (!tp[i])
            cout << i+1;
    return 0;
}
