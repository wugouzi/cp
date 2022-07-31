//
// Created by wu on 2022/7/14.
//

#include "leetcode.h"

class WordFilter {
public:
    struct Trie {
        unordered_map<string, Trie*> ch;
        int ind;
        Trie() : ind(-1) {}
        Trie(int k) : ind(k){}
    } *root;

    WordFilter(vector<string>& words) {
        root = new Trie();
        for (int i = 0; i < words.size(); i++){
            string word = words[i];
            int n = word.size();
            Trie* tmp = root;
            Trie* cur = root;
            for (int j = 0; j < n; j++) {
                cur = tmp;
                for (int k = j; k < n; k++) {
                    string key({word[k],'#'});
                    if (!cur->ch.count(key))
                        cur->ch[key] = new Trie();
                    cur = cur->ch[key];
                    cur->ind = i;
                }
                cur = tmp;
                for (int k = j; k < n; k++) {
                    string key({'#',word[n-1-k]});
                    if (!cur->ch.count(key))
                        cur->ch[key] = new Trie();
                    cur = cur->ch[key];
                    cur->ind = i;
                }
                string  key({word[j],word[n-1-j]});
                if (!tmp->ch.count(key))
                    tmp->ch[key] = new Trie();
                tmp = tmp->ch[key];
                tmp->ind = i;
            }
        }
    }

    int f(string pref, string suff) {
        int n1 = pref.size(), n2 = suff.size();
        if (n1 > n2) {
            string tp = "";
            for (int i = 0; i < n1 - n2; i++)
                tp += '#';
            suff = tp+suff;
        }
        else if (n1 < n2) {
            for (int i = 0; i < n2 - n1; i++)
                pref += '#';
            n1 = n2;
        }
        Trie *tp = root;
        for (int i = 0; i < n1; i++) {
            string t({pref[i],suff[n1-i-1]});
            if (!tp->ch.count(t))
                return -1;
            tp = tp->ch[t];
        }
        return tp->ind;
    }
};

int main(void) {
    vector<string> tp = {"cwwefewf"};
    vector<vector<string>> ff = {{"cw","wf"}};
    WordFilter a(tp);
    for (auto& fff : ff) {
        int k = a.f(fff[0],fff[1]);
        if (k == 5412) {
            k++;
        }
        cout << k << endl;
    }
}