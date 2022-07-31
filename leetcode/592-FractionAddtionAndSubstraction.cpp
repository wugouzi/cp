//
// Created by wu on 2022/7/27.
//

#include "leetcode.h"

struct frac {
    int nu;
    int de;
};
frac add(frac& s1, frac& s2) {
    frac res;
    if (s1.de != s2.de) {
        int tp = gcd(s1.de, s2.de);
        int t1 = s2.de / tp;
        int t2 = s1.de / tp;
        s1.nu *= t1;
        s1.de *= t1;
        s2.nu *= t2;
        s2.de *= t2;
    }
    res.de = s1.de;
    res.nu = s1.nu + s2.nu;
    return res;
}
frac sub(frac& s1, frac& s2) {
    s2.nu = -s2.nu;
    return add(s1, s2);
}
string fractionAddition(string expression) {
    frac res, tmp;
    res.nu = 0;
    res.de = 1;
    bool mi = false;
    int n = expression.size();
    for (int i = 0; i < expression.size(); i++) {
        mi = false;
        if (expression[i++] == '-')
            mi = true;
        int tp = 0;
        if (i == 1 && isdigit(expression[0]))
            i--;
        while (isdigit(expression[i])) {
            tp = tp*10+expression[i]-'0';
            i++;
        }
        tmp.nu = tp;
        i++;
        tp = 0;
        while (isdigit(expression[i]) && i < n) {
            tp = tp*10+expression[i]-'0';
            i++;
        }
        i--;
        tmp.de = tp;
        if (mi)
            res = sub(res, tmp);
        else
            res = add(res,tmp);
    }
    if (res.nu == 0)
        res.de = 1;
    if (res.nu != 0) {
        int tp = gcd(res.de, res.nu);
        if (tp > 1) {
            res.de /= tp;
            res.nu /= tp;
        }
    }
    return to_string(res.nu)+"/"+to_string(res.de);
}

int main() {
    cout << fractionAddition("1/3-1/2");
}