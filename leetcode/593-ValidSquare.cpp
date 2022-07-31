//
// Created by wu on 2022/7/29.
//

#include "leetcode.h"

bool check(vector<int>& t1, vector<int>& t2, vector<int>& t3) {
    int x1 = t2[0]-t1[0];
    int x2 = t3[0]-t1[0];
    int y1 = t2[1]-t1[1];
    int y2 = t3[1]-t1[1];
    if ((x1==0 && y2 == 0) || (x2==0 && y1==0))
        return true;
    if (!x1 || !x2)
        return false;
    if (y1*y2 == -x1*x2)
        return true;
    return false;
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    return check(p1, p2, p3) && check(p2,p1,p3) && check(p3,p2,p4);
}

int main(void) {
    vector<int> t1 = {0,0}, t2 = {1,1}, t3 = {1,0},
    t4 = {0,12};
    cout << 0 + validSquare(t1, t2, t3, t4);
}