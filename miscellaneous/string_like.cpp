#include <iostream>
#include <string>
#include <vector>

bool string_like(const char *s1, const char *s2)
{
  std::cout << "s1: " << s1 << " s2: " << s2 << ":";
  int n = strlen(s1), m = strlen(s2);
  auto match = [&](int i, int j) {
    if (i == 0 || j == 0) return false;
    return s1[i-1] == s2[j-1] || s2[j-1] == '_';
  };
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
  dp[0][0] = true;
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s2[j-1] == '%') {
        dp[i][j] |= dp[i][j-1];
        if (i > 0) {
          dp[i][j] |= dp[i-1][j];
        }
      } else {
        if (match(i, j)) {
          dp[i][j] = dp[i-1][j-1];
        } else {
          dp[i][j] = false;
        }
      }
    }
  }
  if (dp[n][m]) {
    std::cout << " like" << std::endl;
  } else {
    std::cout << " not like" << std::endl;
  }
  return dp[n][m];
}

int main(void) {

  string_like("apple", "p%");
  string_like("apple", "%e");
  string_like("taewfweft", "t%t");
  string_like("test", "%t");
  string_like("abssss", "abs");
  string_like("wwww", "w%");
  string_like("wwww", "w_%");
  string_like("wwww", "wwww%");
  string_like("not like", "___");
  string_like("___", "___");
  string_like("aaa", "aa");
}
