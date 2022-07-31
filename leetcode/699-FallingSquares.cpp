#include "leetcode.h"


vector<int> lazy, s;
//[l,r)
void upd(int id, int l, int r, int x) {
    lazy[id] = x;
    s[id] = x;
}

void shift(int id, int l, int r) {
    int mid = (l+r)/2;
    upd(id*2,l,mid,lazy[id]);
    upd(id*2+1,mid,r,lazy[id]);
    lazy[id] = 0;
}

void increase(int x, int y, int v, int id, int l, int r) {
    if (v == 0) return;
    if (x >= r || y <= l || l >= r) return;
    /*if (r - l == 1) {
        s[id] += v;
        return;
    }*/
    if ((y >= r && x <= l)) {
        s[id] = v;
        lazy[id] = v;
        return;
    }
    if (lazy[id])
        shift(id,l,r);
    int mid = (l+r)/2;
    increase(x,y,v,id*2,l,mid);
    increase(x, y, v, id*2+1, mid, r);
    s[id] = max(s[id*2+1],s[id*2]);
}

int sum(int x, int y, int id, int l, int r) {
    if (x >= r || y <= l) return 0;
    if (x <= l && r <= y) return s[id];
    if (lazy[id])
        shift(id,l,r);
    int mid = (l+r)/2;
    return max(sum(x,y,id*2,l,mid),sum(x,y,id*2+1,mid,r));
}


vector<int> fallingSquares(vector<vector<int>>& positions) {
    lazy.resize(10000);
    s.resize(10000);
    vector<int> nums;
    for (auto& p : positions)
        nums.push_back(p[0]),nums.push_back(p[0]+p[1]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()), nums.end());
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]] = i;
    int l = 0, r = mp.size()-1;
    vector<int> ans;
    for (auto& pos : positions) {
        int x = mp[pos[0]], y = mp[pos[1]+pos[0]], h = pos[1];
        h += sum(x,y,1,l,r);
        increase(x,y,h,1,l,r);
        ans.push_back(s[1]);
    }
    return ans;
}

int main(void) {
    //vector<vector<int>> t = {{1,2},{2,3},{6,1}};
    //vector<vector<int>> t = {{100,100},{200,100}};
    //vector<vector<int>> t = {{9,7},{1,9},{3,1}};
    //vector<vector<int>> t = {{9,6},{2,2},{2,6}};
    vector<vector<int>> t = {{5,10},{1,7},{1,2},{9,3},{1,6}};
    auto tp = fallingSquares(t);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}