//
// Created by wu on 2022/5/29.
//

#include "leetcode.h"

bool check4(string ip) {
    int n = ip.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int zero = 0;
        if (!isdigit(ip[j]) && ip[j] != '.') return false;
        while (j < n && isdigit(ip[j])) {
            if (ip[j] == '0' && zero == 0)
                zero = 1;
            else if (zero == 1)
                return false;
            else if (ip[j] != '0' && zero == 0)
                zero = 2;
            j++;
        }
        if (j == n-1 && ip[j] == '.') return false;
        if (i == j) return false;
        cnt++;
        if (cnt > 4) return false;
        int tp = stoi(ip.substr(i,j-i+1));
        if (tp > 255) return false;
        i = j;
    }
    if (cnt < 4) return false;
    return true;
}

bool check6(string ip) {
    int n = ip.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && isalnum(ip[j]))
            j++;
        if (j-i > 4 || i == j) return false;
        cnt++;
        if (j == n-1 && ip[j] == ':') return false;
        if (cnt > 8)
            return false;
        i = j;
    }
    if (cnt < 8) return false;
    return true;
}
string validIPAddress(string queryIP) {
    for (auto& c : queryIP) {
        if (c == '.')
            if (check4(queryIP))
                return "IPv4";
            else return "Neither";
        if (c == ':')
            if (check6(queryIP))
                return "IPv6";
            else return "Neither";
    }
    return "";
}

int main(void) {
    cout << validIPAddress("172.16.254.1");
}