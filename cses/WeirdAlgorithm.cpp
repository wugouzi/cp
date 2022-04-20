//
// Created by wu on 2022/4/20.
//

#include <iostream>
using namespace std;
int main(void) {
    unsigned long long n;
    cin >> n;
    while (n != 1) {
        cout << n << ' ';
        if (n % 2)
            n = 3*n+1;
        else
            n /= 2;
    }
    cout << '1';
}