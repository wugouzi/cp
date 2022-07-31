//
// Created by wu on 2022/5/22.
//

#include "leetcode.h"

/*int totalStrength(vector<int>& strength) {
    int N = 1e9+7, n = strength.size();
    vector<int> psum(n);
    psum[0] = strength[0];
    for (int i = 1; i < n; i++)
        psum[i] = psum[i-1]+strength[i];
    vector<int> left(n), right(n);
    stack<int> de,dee;
    for (int i = 0; i < n; i++) {
        while (!de.empty() && strength[de.top()] >= strength[i])
            de.pop();
        left[i] = de.empty() ? 0 : de.top()+1;
        de.push(i);
        while (!dee.empty() && strength[dee.top()] > strength[n-i-1])
            dee.pop();
        right[n-i-1] = dee.empty() ? n-1 : dee.top()-1;
        dee.push(n-i-1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = left[i]; 0<= j && j <= i; j++)
            for (int k = right[i]; n-1 >= k && k>= i; k--)
                ans += strength[i]*(psum[k]-(j-1<0?0:psum[j-1]));
    }
    return ans;
}*/

int totalStrength(vector<int>& strength) {
    int N = 1000000007, n = strength.size();
    fstream f("../leetcode/test");
    vector<long long> psum(n),ppsum(n);
    psum[0] = strength[0];
    for (int i = 1; i < n; i++) {
        psum[i] = psum[i-1]+strength[i];
        //if (psum[i] < 0) cout << -1 << endl;
        psum[i] %= N;
    }
    ppsum[0] = psum[0];
    for (int i = 1; i < n; i++) {
        ppsum[i] = ppsum[i-1]+psum[i];
        //if (ppsum[i] < 0) cout << -2 << endl;
        ppsum[i] %= N;
    }
    vector<int> left(n), right(n);
    stack<int> de,dee;
    for (int i = 0; i < n; i++) {
        while (!de.empty() && strength[de.top()] >= strength[i])
            de.pop();
        left[i] = de.empty() ? 0 : de.top()+1;
        de.push(i);
        while (!dee.empty() && strength[dee.top()] > strength[n-i-1])
            dee.pop();
        right[n-i-1] = dee.empty() ? n-1 : dee.top()-1;
        dee.push(n-i-1);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long tp = 0;
        long long m2 = right[i]-i+1;
        long long m1 = i-left[i]+1;
        tp += (m1*ppsum[right[i]]);
        if (ppsum[i-1] > N) cout << ppsum[i-1];
        if (i>0) tp -= ((m1+m2)*ppsum[i-1]);
        if (left[i]>1) tp += (m2*ppsum[left[i]-2]);
        tp = (tp%N+N)%N;
        ans = ((ans+strength[i]*tp)%N+N)%N;
    }
    return ans;
}

int main(void) {
    cout << totalStrength(str);
}
