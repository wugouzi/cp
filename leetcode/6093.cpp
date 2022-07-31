//
// Created by wu on 2022/6/5.
//

#include "leetcode.h"

class TextEditor {
public:
    struct node {
        char c;
        node* left;
        node* right;
        node(int k): c(k), left(nullptr), right(nullptr){}
    };
    int len;
    int curpos;
    node* curnode,*root;
    TextEditor() {
        len = 0;
        curpos = 0;
        curnode = new node(0);
        root = curnode;
    }

    void addText(string text) {
        len += text.size();
        curpos += text.size();
        for (auto& c : text) {
            node* tp = new node(c), *tpp = curnode->right;
            curnode->right = tp;
            tp->left = curnode;
            tp->right = tpp;
            if (tpp)
                tpp->left = tp;
            curnode = curnode->right;
        }
    }

    int deleteText(int k) {
        int cnt = 0;
        node* tp = curnode->right;
        while (k && curnode->left) {
            curnode = curnode->left;
            delete curnode->right;
            curnode->right = nullptr;
            k--;
            cnt++;
        }
        curnode->right = tp;
        if (tp)
            tp->left = curnode;
        return cnt;
    }

    string cursorLeft(int k) {
        string tp;
        while (k && curnode->left) {
            curnode = curnode->left;
            k--;
        }
        node* tpp = curnode;
        int kk = 10;
        while (kk && tpp->left) {
            tp.push_back(tpp->c);
            tpp = tpp->left;
            kk--;
        }
        reverse(tp.begin(),tp.end());
        return tp;
    }

    string cursorRight(int k) {
        string tp;
        while (k && curnode->right) {
            curnode = curnode->right;
            k--;
        }
        node* tpp = curnode;
        int kk = 10;
        while (kk && tpp->left) {
            tp.push_back(tpp->c);
            tpp = tpp->left;
            kk--;
        }
        reverse(tp.begin(),tp.end());
        return tp;
    }
};

int main(void) {
    TextEditor textEditor; // 当前 text 为 "|" 。（'|' 字符表示光标）
    textEditor.addText("leetcode"); // 当前文本为 "leetcode|" 。
    textEditor.deleteText(4); // 返回 4
    // 当前文本为 "leet|" 。
    // 删除了 4 个字符。
    textEditor.addText("practice"); // 当前文本为 "leetpractice|" 。
    cout << textEditor.cursorRight(3) << endl; // 返回 "etpractice"
    // 当前文本为 "leetpractice|".
    // 光标无法移动到文本以外，所以无法移动。
    // "etpractice" 是光标左边的 10 个字符。
    cout << textEditor.cursorLeft(8) << endl; // 返回 "leet"
    // 当前文本为 "leet|practice" 。
    // "leet" 是光标左边的 min(10, 4) = 4 个字符。
    cout << textEditor.deleteText(10) << endl; // 返回 4
    // 当前文本为 "|practice" 。
    // 只有 4 个字符被删除了。
    cout << textEditor.cursorLeft(2)  << endl; // 返回 ""
    // 当前文本为 "|practice" 。
    // 光标无法移动到文本以外，所以无法移动。
    // "" 是光标左边的 min(10, 0) = 0 个字符。
    cout << textEditor.cursorRight(6) << endl; // 返回 "practi"
    // 当前文本为 "practi|ce" 。
    // "practi" 是光标左边的 min(10, 6) = 6 个字符。
}