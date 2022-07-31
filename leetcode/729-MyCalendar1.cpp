#include "leetcode.h"



class MyCalendar {
public:
    struct Node {
        int ls, rs, add, val, l, r;

        Node() : ls(0), rs{0}, add(0), val(0), l(-1) {}
    };
    int N = 1e9, M = 1e6, cnt = 1;
    vector<Node *> tr = vector<Node *>(M, nullptr);
    bool debug;
    void lazycreate(int u) {
        if (!tr[u])
            tr[u] = new Node();
        if (tr[u]->ls == 0) {
            tr[u]->ls = ++cnt;
            tr[tr[u]->ls] = new Node();
        }
        if (tr[u]->rs == 0) {
            tr[u]->rs = ++cnt;
            tr[tr[u]->rs] = new Node();
        }
    }

    void pushdown(int u, int len) {
        if (tr[u]->add != 0 || len != 0) {
            tr[tr[u]->ls]->add += tr[u]->add;
            tr[tr[u]->rs]->add += tr[u]->add;
            tr[tr[u]->ls]->val += (len - len / 2) * tr[u]->add;
            tr[tr[u]->rs]->val += len / 2 * tr[u]->add;
            tr[u]->add = 0;
        }
    }

    void pushup(int u) {
        tr[u]->val = tr[tr[u]->ls]->val + tr[tr[u]->rs]->val;
    }

    void update(int u, int lc, int rc, int l, int r, int v) {
        if (tr[u]->l == -1) {
            tr[u]->l = lc;
            tr[u]->r = rc;
        }
        if (l <= lc && rc <= r) {
            tr[u]->val += (rc - lc + 1) * v;
            tr[u]->add += v;
            return;
        }
        lazycreate(u);
        pushdown(u, rc - lc + 1);
        int mid = (lc + rc) >> 1;
        if (l <= mid)
            update(tr[u]->ls, lc, mid, l, r, v);
        if (r > mid)
            update(tr[u]->rs, mid + 1, rc, l, r, v);
        pushup(u);
        if (debug) {
            cout << tr[u]->l << ' ' << tr[u]->r << ' ' << tr[u]->val << endl;
        }
    }

    int query(int u, int lc, int rc, int l, int r) {
        if (l <= lc && rc <= r)
            return tr[u]->val;
        lazycreate(u);
        pushdown(u, rc-lc+1);
        int mid = (lc + rc) >> 1, ans = 0;
        if (l <= mid)
            ans = query(tr[u]->ls, lc, mid, l, r);
        if (r > mid)
            ans += query(tr[u]->rs, mid + 1, rc, l, r);

        return ans;
    }

    MyCalendar() {
        debug = false;
    }

    bool book(int start, int end) {
        if (query(1, 0, N, start, end-1) > 0) return false;
        update(1, 0, N, start, end-1, 1);
        return true;
    }
};
//"book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book"]


//true,false,false,false,false,false,false,false,false,false,false,false,false,false]
int main(void) {
    MyCalendar ca;
    /*
    cout << 0 + ca.book(10,20);
    cout << 0 + ca.book(15,25);
    cout << 0 + ca.book(20,30);
     */
    ca.debug = false;
    cout << 0 + ca.book(40,49);
    cout << 0 + ca.book(40,49);//false
    cout << 0 + ca.book(49,50);
    cout << 0 + ca.book(49,50);//false
    cout << 0 + ca.book(27,34);
    cout << 0 + ca.book(23,30);//false
    cout << 0 + ca.book(39,46);//false
    cout << 0 + ca.book(8,15);
    cout << 0 + ca.book(3,9);//false
    cout << 0 + ca.book(2,8);
    cout << 0 + ca.book(48,50);//false
    cout << 0 + ca.book(46,50);//false
    cout << 0 + ca.book(4,12);//false
    cout << 0 + ca.book(4,10);//false
    cout << 0 + ca.book(30,36);//false
    cout << 0 + ca.book(47,50);//false
    cout << 0 + ca.book(15,23);
    cout << 0 + ca.book(43,50);//false
    cout << 0 + ca.book(49,50);
    cout << 0 + ca.book(24,33);
    cout << 0 + ca.book(17,26);
    cout << 0 + ca.book(3,11);
    cout << 0 + ca.book(45,50);
    cout << 0 + ca.book(3,8);
    ca.debug = false;
    cout << 0 + ca.book(32,40);

    cout << 0 + ca.book(37,43);
    cout << 0 + ca.book(5,13);
    cout << 0 + ca.book(0,9);
    cout << 0 + ca.book(48,50);
    cout << 0 + ca.book(14,22);
}
