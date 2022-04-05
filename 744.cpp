//
// Created by wu on 2022/4/3.
//

#include "leetcode.h"

char nextGreatestLetter(vector<char>& letters, char target) {
    int l = 0, r = letters.size()-1;
    while (l < r) {
        int med = (l+r)/2;
        if (letters[med] < target)
            l = med+1;
        else if (letters[med] >= target)
            r = med;
        cout << l << ' ' << r << endl;
    }
    return letters[l];
}

int main(void) {
    vector<char> l = {'c', 'f', 'j'};
    cout << nextGreatestLetter(l, 'a');
}