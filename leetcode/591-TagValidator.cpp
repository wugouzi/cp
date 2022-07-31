//
// Created by wu on 2022/5/2.
//

#include "leetcode.h"

bool check_tag(string& tag) {
    if (tag.size() > 9 || tag.size() < 1)
        return false;
    for (auto& c : tag)
        if (c < 'A' || c > 'Z')
            return false;
    return true;
}
int check_cdata(string& code, int i) {
    if (i+9 >= code.size()) return -1;
    if (code[i]!='['||code[i+1]!='C'||code[i+2]!='D'||code[i+3]!='A'||code[i+4]!='T'||code[i+5]!='A'||code[i+6]!='[')
        return -1;
    int cnt=1, j=i+7;
    while (j+2<code.size()&&(code[j]!=']'||code[j+1]!=']'||code[j+2]!='>')) {
        j++;
    }
    j = j+2;
    if (j>=code.size()||code[j]!='>') return -1;
    return j+1;
}
int check_etag(string& code, stack<string>& s, int i) {
    int j = i;
    while (j < code.size() && code[j] != '>') j++;
    if (j>=code.size() || j-i>10 || j==i) return -1;
    string tp = code.substr(i,j-i);
    if (s.empty() || s.top() != tp || !check_tag(tp)) return -1;
    s.pop();
    return j+1;
}
int check_tag(string& code, stack<string>& s, int i) {
    int j = i;
    while (j < code.size() && code[j] != '>') {
        j++;
    }
    if (j >= code.size() || j-i > 10 || j == i) return -1;
    string tp = code.substr(i,j-i);
    if (!check_tag(tp))
        return -1;
    s.push(tp);
    return j+1;
}
bool isValid(string code) {
    stack<string> tag_name;
    for (int i = 0; i < code.size();) {
        if (code[i] == '<') {
            if (i+1 == code.size()) return false;
            if (code[i+1] == '/') {
                if (tag_name.empty()) return false;
                if ((i=check_etag(code, tag_name, i+2)) == -1)
                    return false;
            } else if (code[i+1] == '!') {
                if (tag_name.empty()) return false;
                if ((i=check_cdata(code,i+2))==-1)
                    return false;
            } else {
                if (tag_name.empty()&&i!=0) return false;
                if ((i=check_tag(code, tag_name, i+1)) == -1)
                    return false;
            }
        } else {
            if (tag_name.empty()) return false;
            i++;
        }
    }
    if (!tag_name.empty()) return false;
    return true;
}

int main(void) {
    string c = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    cout << 0+ isValid(c);
}