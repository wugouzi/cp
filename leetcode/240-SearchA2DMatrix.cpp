//
// Created by wu on 2022/3/7.
//
#include <vector>
#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int l = 0, r = n-1;
    while(l < r) {
        int med = (l+r)/2;
        if (target<matrix[med][0]) r = med-1;
        else if (target>matrix[med][0])
            if (l == med) break;
            else l = med;
        else return true;
    }
    int row = l;
    l = 0;
    r = m-1;
    while(l<r) {
        int med = (l+r)/2;
        if (target<matrix[row][med]) r = med - 1;
        else if (target>matrix[row][med]) l = med + 1;
        else return true;
    }
    if (matrix[row][l] == target) return true;
    return false;
}

int main(void) {
    vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int k = 5;
    cout << searchMatrix(mat, k);
}
