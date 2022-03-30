//
// Created by wu on 2022/2/24.
//
#include<iostream>

using namespace std;

int reverse(int x) {
    if (x <= INT_MIN || x >= INT_MAX) return 0;
    int tp = x;
    cout << INT_MIN << endl << INT_MAX<<endl;
    x = abs(x);
    if (x / 10 == 0) return x;
    while (x % 10 == 0) x /= 10;
    int y = 0;
    while (x) {
        if (y > (INT_MAX - x % 10) / 10) return 0;
        y = y * 10 + (x % 10);
        x /= 10;
    }

    return tp > 0 ? y : -y;
}

int main(void) {
    int tp =-2147483648;
    cout << reverse(tp);
}