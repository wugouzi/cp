//
// Created by wu on 2022/10/3.
//

#include "leetcode.h"

struct Trie{
    string w;
    unordered_map<char,Trie*> ch;
}*root;

void insert(string s) {
    Trie *tp = root;
    for (auto &c : s) {
        if (!tp->ch.count(c))
            tp->ch[c] = new Trie();
        tp = tp->ch[c];
    }
    tp->w = s;
}
unordered_map<int,vector<string>> mp;
void help(string &s, int d) {
    Trie *tp = root;
    mp[d];
    for (int i = d; i < s.size(); i++) {
        if (tp->ch.count(s[i]))
            tp = tp->ch[s[i]];
        else
            break;
        if (tp->w != "") {
            string t = tp->w;
            if (i + 1 == s.size()) {
                mp[d].push_back(t);
                break;
            }
            if (!mp.count(i+1))
                help(s, i+1);
            for (auto &v : mp[i+1])
                mp[d].push_back(t+' '+v);
        }
    }
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    root = new Trie();
    for (auto &s : wordDict)
        insert(s);
    help(s, 0);
    return mp[0];
}

int main(void) {
    string s = "catsanddog";
    vector<string> d{"cat","cats","and","sand","dog"};
    vector<string> tp = wordBreak(s,d);
    for (auto &s : tp) cout << s << ' ';
}