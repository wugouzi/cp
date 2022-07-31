//
// Created by wu on 2022/7/10.
//

#include "leetcode.h"

bool canChange(string start, string target) {
    int n = target.size();
    for (int i = 0; i < n; i++) {
        if (start[i] == target[i])
            continue;
        if (target[i] == '_') {
            if (start[i] == 'R') {
                int j;
                for (j = i+1; j < n; j++) {
                    if (start[j] == 'L')
                        return false;
                    if (start[j] == '_') {
                        swap(start[j],start[i]);
                        break;
                    }
                }
                if (j == n)
                    return false;
            } else
                return false;
        } else if (target[i] == 'L') {
            if (start[i] == '_') {
                int j = i;
                while (j < n && start[j] == '_') j++;
                if (start[j] == 'L')
                    swap(start[j],start[i]);
                else
                    return false;
            } else
                return false;
        } else if (target[i] == 'R')
            return false;
    }
    return true;
}

int main(void) {
    string s = "_L__R__R_";
    string t = "L______RR";
    cout << 0+canChange(s,t);
}