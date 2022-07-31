//
// Created by wu on 2022/4/6.
//

#include "leetcode.h"

string fractionToDecimal(int numerator, int denominator) {
    long long nu = numerator, de = denominator;
    string ans;
    if ((nu < 0 && de > 0) || (nu > 0 && de < 0)) {
        ans.push_back('-');
        nu = abs(nu);
        de = abs(de);
    }
    long long ip = nu/de, ir = nu%de;
    if (ir == 0) return to_string(ip);
    ans = ans + to_string(ip);
    ans.push_back('.');
    string frac;
    unordered_map<long long, int> place;
    int i = 1;
    place[ir] = 0;
    while(1) {
        nu = ir*10;
        ip = nu/de;
        ir = nu%de;
        frac.push_back(ip+'0');
        if (ir == 0)
            return ans+frac;
        if (place.count(ir)) {
            frac.insert(place[ir], "(");
            frac.push_back(')');
            return ans+frac;
        }
        place[ir] = i++;
    }
    return "wrong";
}

int main(void) {
    cout << fractionToDecimal(-2147483648, 1);
}
