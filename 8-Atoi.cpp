//
// Created by wu on 2022/2/24.
//
#include<string>
#include<iostream>
using namespace std;

int myAtoi(string s) {
    int n = s.size();
    long long num = 0;
    int i = 0;
    bool sign = true;
    bool pos = true;
    while (s[i++] == ' ');
    i--;
    for (; i < n; i++) {
        if ((s[i] == '+' || s[i] == '-') && sign) {
            sign = false;
            if (s[i] == '-') pos = false;
        } else if ('0' <= s[i] && s[i] <= '9') {
            sign = false;
            int tp = s[i]- '0';
            long long ans = num * 10 + tp;
            if (pos && ans > (long long)INT_MAX) return INT_MAX;
            if (!pos && -ans < (long long)INT_MIN) return INT_MIN;
            num = ans;
        } else {
            break;
        }
    }
    return pos ? num : -num;

    // int n = s.size();
    // bool pos = true;
    // bool sign = false;
    // bool isnum = false;
    // int num = 0;
    // int digit = 0;
    // for (int i = 0; i < n; i++) {
    //     if (s[i] == '-' || s[i] == '+') {
    //         if (sign || isnum) break;
    //         sign = true;
    //         pos = s[i] == '-' ? false : true;
    //     } else if ('0' <= s[i] && s[i] <= '9') {
    //         int tp = s[i] - '0';
    //         if (digit == 9 || (pos && num > (INT_MAX - tp)/10) || (!pos && -num < (INT_MIN + tp)/10)) return pos ? INT_MAX : INT_MIN;
    //         num = num * 10 + tp;
    //         isnum = true;
    //     } else if (s[i] != ' ' || (isnum && s[i] == ' ')){
    //         break;
    //     }
    // }
    // return pos ? num : -num;
}

int main (void) {
    string s = "-91283472332";
    cout << myAtoi(s);
}
