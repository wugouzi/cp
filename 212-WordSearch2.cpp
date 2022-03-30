//
// Created by wu on 2022/3/16.
//

#include "leetcode.h"

struct Trie {
    string word;
    unordered_map<char, Trie*> child;
    Trie(): word("") {}
};
void insert(Trie* root, string& s) {
    for (char c : s) {
        if (!root->child.count(c)) {
            root->child[c] = new Trie();
        }
        root = root->child[c];
    }
    root->word = s;
}
vector<string> ans;
int n, m;
void check(vector<vector<char>>& board, Trie* node, int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < m && node->child.count(board[i][j])) {
        node = node->child[board[i][j]];
        if (node->word != "") ans.push_back(node->word);
        char tp = board[i][j];
        board[i][j] = '#';
        check(board, node, i+1,j);
        check(board, node, i-1,j);
        check(board, node, i, j+1);
        check(board,node,i,j-1);
        board[i][j] = tp;
    }
    return;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie *root = new Trie();
    n = board.size();
    m = board[0].size();
    for (auto& s : words) insert(root, s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            check(board, root, i, j);
        }
    }
    return ans;
}

int main(void) {
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string>  words = {"oath","pea","eat","rain"};
    vector<string> tp = findWords(board, words);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}