//
// Created by wu on 2022/4/3.
//

#include "leetcode.h"

class Encrypter {
public:
    unordered_map<string, vector<char>> de;
    unordered_map<char, string> en;
    struct Trie {
        string word;
        unordered_map<char, Trie*> child;
        Trie():word(""){}
    } *tree;
    void insert(Trie* tree, string word) {
        int n = word.size();
        for (int i = n-1; i >= 0; i--) {
            if (!tree->child.count(word[i])) {
                tree->child[word[i]] = new Trie();
            }
            tree = tree->child[word[i]];
        }
        tree->word = word;
    }
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        tree = new Trie;
        for (int i = 0; i < n; i++) {
            en[keys[i]] = values[i];
            de[values[i]].push_back(keys[i]);
        }
        for (int i = 0; i < dictionary.size(); i++)
            insert(tree, dictionary[i]);
    }
    string encrypt(string word1) {
        string ans;
        for (auto& c : word1)
            ans = ans + en[c];
        return ans;
    }

    int dec(string word, int i, Trie* node) {
        if (i == word.size()) {
            if (node->word == "")
                return 0;
            return 1;
        }
        int cnt = 0;
        vector<char> tp = de[word.substr(i,2)];
        for (auto& c : tp) {
            if (node->child.count(c))
                cnt += dec(word, i-2, node->child[c]);
        }
        return cnt;
    }

    int decrypt(string word2) {
        return dec(word2, word2.size()-2, tree);
    }
};

int main(void) {
    vector<char> keys = {'a', 'b', 'c', 'd'};
    vector<string> t1 = {"ei", "zf", "ei", "am"};
    vector<string> t2 = {"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"};
    Encrypter encrypter(keys, t1, t2);
    cout << encrypter.encrypt("abcd") << endl;
    cout << encrypter.decrypt("eizfeiam");

}