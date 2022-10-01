//
// Created by wu on 2022/10/1.
//

#include "leetcode.h"

string reformatNumber(string number) {
    string s;
    for (auto &c : number)
        if (isdigit(c))
            s.push_back(c);
    int n = s.size();
    auto it = s.begin();
    while (n > 4) {
        it += 3;
        s.insert(it, '-');
        it++;
        n -= 3;
    }
    cout << s << endl;
    if (n == 4) {
        it += 2;
        s.insert(it, '-');
    }
    return s;
}

int main(void) {
    cout << reformatNumber("--17-5 229 35-39475 ");
}