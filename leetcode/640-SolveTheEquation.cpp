//
// Created by wu on 2022/8/10.
//

#include "leetcode.h"

string solveEquation(string equation) {
    int lx = 0, ls = 0;
    int n = equation.size();
    int op = 1;
    int met = 1;
    for (int i = 0; i < n; i++) {
        if (equation[i] == '=') {
            met = -1;
            op = -1;
        } else if (equation[i] == '-') {
            op = -1 * met;
        } else if (equation[i] == '+') {
            op = 1 * met;
        } else if (equation[i] == 'x') {
            lx += op;
        } else if (isdigit(equation[i])) {
            int tp = 0;
            while (isdigit(equation[i])) {
                tp = tp*10+equation[i]-'0';
                i++;
            }
            if (i < n && equation[i] == 'x') {
                lx += op * tp;
            } else {
                ls += op * tp;
                i--;
            }
        }
    }
    if (lx == 0) {
        return "Infinite solutions";
    } else {
        return "x=" + to_string(-ls / lx);
    }
}

int main(void) {
    cout << solveEquation("x+5-3+x=6+x-2");
}