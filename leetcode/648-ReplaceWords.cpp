//
// Created by wu on 2022/7/7.
//

#include "leetcode.h"

struct node {
    string word;
    unordered_map<char,node*> ch;
};
void insert(node* root, string w) {
    for (auto& c : w) {
        if (!root->ch.count(c)) {
            root->ch[c] = new node();
        }
        root = root->ch[c];
    }
    root->word = w;
}

string check(node* root, string w) {
    for (auto& c : w) {
        if (root->ch.count(c))
            root = root->ch[c];
        else
            return w;
        if (root->word != "")
            return w;
    }
    return w;
}
string replaceWords(vector<string>& dictionary, string sentence) {
    string ans;
    int j = 0;
    node *root = new node();
    for (auto& w : dictionary)
        insert(root, w);
    sentence.push_back(' ');
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ' ') {
            string tp = sentence.substr(j, i-j);
            ans += check(root,tp);
            ans.push_back(' ');
            j = i+1;
        }
    }
    ans.pop_back();
    return ans;
}

int main(void) {
    vector<string> t = {"cat","bat","rat"};
    string s = "the cattle was rattled by the battery";
    cout << replaceWords(t,s);
}