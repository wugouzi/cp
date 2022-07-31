//
// Created by wu on 2022/7/26.
//

#include "leetcode.h"

class Skiplist {
public:
    struct Node {
        vector<Node*> next;
        int level;
        int val;
        int cnt;
    } *root;
    int maxlevel;
    double prob;
    int newlevel() {
        int curlevel = 1;
        while (1.0*rand()/RAND_MAX < prob && curlevel <= maxlevel)
            curlevel++;
        return curlevel;
    }
    Node* newnode(int k) {
        Node* t = new Node();
        t->next.resize(maxlevel);
        t->level = newlevel();
        t->val = k;
        t->cnt = 1;
        return t;
    }
    Node* newnode(int k, int l) {
        Node* t = new Node();
        t->next.resize(maxlevel);
        t->level = l;
        t->val = k;
        t->cnt = 1;
        return t;
    }
    Skiplist() {
        maxlevel = 4;
        prob = 0.5;
        srand(time(nullptr));
        root = newnode(INT_MIN, maxlevel);
        Node* end = newnode(INT_MAX, maxlevel);
        for (int i = 0; i < maxlevel; i++)
            root->next[i] = end;
    }
    bool search(int target) {
        Node* tp = root;
        for (int i = maxlevel-1; i >= 0; i--) {
            while (target >= tp->next[i]->val)
                tp = tp->next[i];
        }
        if (tp->val == target)
            return true;
        return false;
    }

    void add(int num) {
        vector<Node*> wait(maxlevel);
        Node* tp = root;
        for (int i = maxlevel-1; i>=0; i--) {
            while (num > tp->next[i]->val) {
                tp = tp->next[i];
            }
            wait[i] = tp;
        }
        tp = tp->next[0];
        if (tp->val == num) {
            tp->cnt++;
            return;
        }
        Node* nn = newnode(num);
        for (int i = 0; i < nn->level; i++) {
            Node* tp = wait[i]->next[i];
            wait[i]->next[i] = nn;
            nn->next[i] = tp;
        }
    }

    bool erase(int num) {
        vector<Node*> wait(maxlevel);
        Node* tp = root;
        for (int i = maxlevel-1; i >= 0; i--) {
            while (num > tp->next[i]->val)
                tp = tp->next[i];
            wait[i] = tp;
        }
        tp = tp->next[0];
        if (tp->val != num)
            return false;
        if (tp->cnt > 1) {
            tp->cnt--;
            return true;
        }
        for (int i = 0; i < tp->level; i++) {
            wait[i]->next[i] = wait[i]->next[i]->next[i];
        }
        return true;
    }

};


int main(void) {
    Skiplist skiplist;
    vector<string> s = {"add","add","add","add","add","add","add","add","add","erase","search","add","erase","erase","erase","add","search","search","search","erase","search","add","add","add","erase","search","add","search","erase","search","search","erase","erase","add","erase","search","erase","erase","search","add","add","erase","erase","erase","add","erase","add","erase","erase","add","add","add","search","search","add","erase","search","add","add","search","add","search","erase","erase","search","search","erase","search","add","erase","search","erase","search","erase","erase","search","search","add","add","add","add","search","search","search","search","search","search","search","search","search"};
    vector<vector<int>> t = {{16},{5},{14},{13},{0},{3},{12},{9},{12},{3},{6},{7},{0},{1},{10},{5},{12},{7},{16},{7},{0},{9},{16},{3},{2},{17},{2},{17},{0},{9},{14},{1},{6},{1},{16},{9},{10},{9},{2},{3},{16},{15},{12},{7},{4},{3},{2},{1},{14},{13},{12},{3},{6},{17},{2},{3},{14},{11},{0},{13},{2},{1},{10},{17},{0},{5},{8},{9},{8},{11},{10},{11},{10},{9},{8},{15},{14},{1},{6},{17},{16},{13},{4},{5},{4},{17},{16},{7},{14},{1}};
    for (int i = 0; i < s.size(); i++) {
        cout << i << ' ' << s[i] << ' ' << t[i][0] << ' ';
        if (t[i][0] == 9)
            cout << "test";
        if (s[i] == "add")
            skiplist.add(t[i][0]);
        else if (s[i] == "erase")
            cout << 0+skiplist.erase(t[i][0]);
        else if (s[i] == "search")
            cout << 0+skiplist.search(t[i][0]);
        cout << endl;
    }
}