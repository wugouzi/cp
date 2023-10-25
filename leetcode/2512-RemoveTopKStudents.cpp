//
// Created by wu on 2023/10/11.
//

#include "leetcode.h"

class Trie {
 public:
  bool end;
  vector<Trie*> next;
  Trie(): end(false), next(vector<Trie*>(26)) {}
} *pos, *neg;
void insert(Trie *ptr, string &str) {
  for (auto &c: str) {
    if (!ptr->next[c - 'a']) {
      ptr->next[c - 'a'] = new Trie();
    }
    ptr = ptr->next[c-'a'];
  }
  ptr->end = true;
}
bool find(Trie *ptr, string::iterator begin, string::iterator end) {
  for (; begin != end; begin++) {
    if ((ptr->next[*begin - 'a']))
      ptr = ptr->next[*begin - 'a'];
    else
      return false;
  }
  return ptr->end;
}


vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
  pos = new Trie();
  neg = new Trie();
  for (auto &s: positive_feedback)
    insert(pos, s);
  for (auto &s: negative_feedback)
    insert(neg, s);
  typedef pair<int, int> pp;
  auto compare = [](const pp &t1, const pp &t2) {
    return t1.first > t2.first || (t1.first == t2.first && t1.second < t2.second);
  };
  priority_queue<pp, vector<pp>, decltype(compare)> q(compare);
  for (int i = 0; i < student_id.size(); i++) {
    auto begin = report[i].begin();
    auto end = report[i].end();
    int score = 0;
    for (auto iter = next(begin); iter != end; iter++) {
      if (*iter == ' ') {
        if (find(pos, begin, iter))
          score += 3;
        if (find(neg, begin, iter))
          score--;
        begin = next(iter);
      }
    }
    if (find(pos, begin, end)) score += 3;
    if (find(neg, begin, end)) score --;
    q.push(make_pair(score, student_id[i]));
    // cout << score << ' ' << student_id[i] << endl;
    if (q.size() > k) q.pop();
  }
  vector<int> ans;
  while (!q.empty()) {
    ans.push_back(q.top().second);
    q.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(void) {
  vector<string> pos = {"fkeofjpc","qq","iio"};
  vector<string> neg = {"jdh","khj","eget","rjstbhe","yzyoatfyx","wlinrrgcm"};
  vector<string> report = {"rjstbhe eget kctxcoub urrmkhlmi yniqafy fkeofjpc iio yzyoatfyx khj iio","gpnhgabl qq qq fkeofjpc dflidshdb qq iio khj qq yzyoatfyx","tizpzhlbyb eget z rjstbhe iio jdh jdh iptxh qq rjstbhe","jtlghe wlinrrgcm jnkdbd k iio et rjstbhe iio qq jdh","yp fkeofjpc lkhypcebox rjstbhe ewwykishv egzhne jdh y qq qq","fu ql iio fkeofjpc jdh luspuy yzyoatfyx li qq v","wlinrrgcm iio qq omnc sgkt tzgev iio iio qq qq","d vhg qlj khj wlinrrgcm qq f jp zsmhkjokmb rjstbhe"};
  vector<int> id = {96537918,589204657,765963609,613766496,43871615,189209587,239084671,908938263};
  int k = 3;
  /*
  vector<string> pos = {"smart","brilliant","studious"};
  vector<string> neg = {"not"};
  vector<string> report = {"this student is not studious","the student is smart"};
  vector<int> id = {1,2};
  int k = 2;*/
  auto test = topStudents(pos, neg, report, id, k);
  pv(test);
}