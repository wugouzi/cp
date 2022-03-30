//
// Created by wu on 2022/3/13.
//

#include "leetcode.h"

vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m;
void fill(vector<vector<int>>& image, int i, int j, int oc, int c) {
    image[i][j] = c;
    for (auto& dir : dirs) {
        int newi = i + dir[0], newj = j + dir[1];
        if (newi >= 0 && newj >= 0 && newi < n && newj < m && image[newi][newj] == oc)
            fill(image, newi, newj, oc, c);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    n = image.size();
    m = image[0].size();
    fill(image, sr, sc, image[sr][sc], newColor);
    return image;
}

int main(void) {
    vector<vector<int>> image = {{0,0,0},{0,1,1}};
    int sr = 1, sc = 1, newcolor = 1;
    floodFill(image, sr, sc, newcolor);
}