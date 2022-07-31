//
// Created by wu on 2022/3/1.
//

#include <map>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> bboard;

bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int k) {
    int n = board.size(), m = board[0].size();
    if (k == word.size() - 1) return true;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    if (word[k] == board[i][j]) k++;

    visited[i][j] = true;
    for (auto&& dir : dirs) {
        int newi = i + dir[0], newj = j + dir[1];
        if (newi >= 0 && newi < n && newj >= 0 && newj < m && !visited[newi][newj] && word[k] == board[newi][newj]) {

            if (check(board, visited, word, newi, newj, k)) return true;
        }
    }
    visited[i][j] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                if (check(board, visited, word, i, j, 0)) return true;
            }
        }
    }
    return false;
}

int main(void) {
    //vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    //string word = "ABCCED";
    //string word = "SEE";
    //string word = "ABCB";
    //vector<vector<char>> board = [['A',"B","C","E"],["S","F","E","S"],["A","D","E","E"]]
    //vector<vector<char>> board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    vector<vector<char>> board = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    //string word = "ABCEFSADEESE";
    string word = "AAAAAAAAAAAAAAB";
    cout << exist(board, word);
}


