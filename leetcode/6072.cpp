//
// Created by wu on 2022/4/17.
//
#include "leetcode.h"
int count5(int k) {
    int ans = 0;
    while (k && k%5==0) {
        ans++;
        k/=5;
    }
    return ans;
}
int count2(int k) {
    int ans = 0;
    while (k && k%2==0) {
        ans++;
        k/=2;
    }
    return ans;
}
int maxTrailingZeros(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<pair<int,int>>> sufh(n, vector<pair<int,int>>(m)), sufv(n, vector<pair<int,int>>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            sufh[i][j].first = count2(grid[i][j]);
            sufh[i][j].second = count5(grid[i][j]);
        }
    for (int i = 0; i < m; i++) {
        sufv[0][i] = sufh[0][i];
    }
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++) {
            sufv[i][j].first = sufv[i-1][j].first+sufh[i][j].first;
            sufv[i][j].second = sufv[i-1][j].second+sufh[i][j].second;
        }

    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++) {
            sufh[i][j].first += sufh[i][j-1].first;
            sufh[i][j].second += sufh[i][j-1].second;
        }
    int ans = 0;
    if (n == 1)
        return min(sufh[0][m-1].first, sufh[0][m-1].second);
    if (m == 1)
        return min(sufv[n-1][0].first, sufv[n-1][0].second);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int c1 = min(sufh[i][m-1].first-sufh[i][j].first+sufv[i][j].first, sufh[i][m-1].second-sufh[i][j].second+sufv[i][j].second);
            int c2 = min(sufh[i][j].first+sufv[n-1][j].first-sufv[i][j].first, sufh[i][j].second+sufv[n-1][j].second-sufv[i][j].second);
            int c3 = min(sufh[i][m-1].first-sufh[i][j].first+sufv[n-1][j].first-sufv[i][j].first+count2(grid[i][j]),
                         sufh[i][m-1].second-sufh[i][j].second+sufv[n-1][j].second-sufv[i][j].second+count5(grid[i][j]));
            int c4 = min(sufh[i][j].first+sufv[i][j].first-count2(grid[i][j]),
                         sufh[i][j].second+sufv[i][j].second-count5(grid[i][j]));
            ans = max(ans,max(c1,max(c2,max(c3,c4))));
        }
    return ans;
}

int main(void) {
    //vector<vector<int>> grid = {{899,727,165,249,531,300,542,890},{981,587,565,943,875,498,582,672},{106,902,524,725,699,778,365,220}};
    //vector<vector<int>> grid = {{10},{6},{15}};
    //vector<vector<int>> grid = {{824,709,193,413,701,836,727},{135,844,599,211,140,933,205},{329,68,285,282,301,387,231},{293,210,478,352,946,902,137},{806,900,290,636,589,522,611},{450,568,990,592,992,128,92},{780,653,795,457,980,942,927},{849,901,604,906,912,866,688}};
    vector<vector<int>> grid = {{242,921,651,509,130,857},{486,959,4,159,150,655},{825,644,838,771,101,199},{781,770,193,492,930,670},{395,474,960,839,616,652},{895,156,833,124,863,907},{603,921,383,279,654,933}};
    cout << maxTrailingZeros(grid);
}

