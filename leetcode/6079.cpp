//
// Created by wu on 2022/5/29.
//

#include "leetcode.h"

string discountPrices(string sentence, int discount) {
    string ans;
    int n = sentence.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        bool flag = true;
        while (j < n && sentence[j] != ' ') {
            j++;
            if (j < n && sentence[j] != ' ' && !isdigit(sentence[j]))
                flag = false;
        }
        if (sentence[i] != '$' || !flag || j-i+1 <= 2) {
            ans += sentence.substr(i, j - i + 1);
        }
        else {
            long long k = stoll(sentence.substr(i+1,j-i-1));
            double res = k*(100-discount)/100.0;
            stringstream stream;
            stream << fixed << setprecision(2) << res;
            string s = stream.str();
            ans += "$"+s;
            if (j < n)
                ans += " ";
        }
        i = j;
    }
    return ans;
}

int main(void) {
    string s = "$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999";
    int dis = 0;
    cout << discountPrices(s,dis);
}