#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;


int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  fstream f("input2");
  string str;
  int sum = 0;
  unordered_map<char, int> mp2;
  mp2['A'] = mp2['X'] = 1;
  mp2['B'] = mp2['Y'] = 2;
  mp2['C'] = mp2['Z'] = 3;
  unordered_map<char, unordered_map<char, int>> mp1;
  mp1['A']['X'] = mp1['B']['Y'] = mp1['C']['Z'] = 3;
  mp1['A']['Y'] = mp1['B']['Z'] = mp1['C']['X'] = 6;
  mp1['A']['Z'] = mp1['B']['X'] = mp1['C']['Y'] = 0;
  unordered_map<char, unordered_map<char, char>> mp3;
  mp3['A']['X'] = 'Z';
  mp3['B']['X'] = 'X';
  mp3['C']['X'] = 'Y';
  mp3['A']['Y'] = 'X';
  mp3['B']['Y'] = 'Y';
  mp3['C']['Y'] = 'Z';
  mp3['A']['Z'] = 'Y';
  mp3['B']['Z'] = 'Z';
  mp3['C']['Z'] = 'X';
  while (getline(f, str)) {
    char c = mp3[str[0]][str[2]];
    sum += mp2[c] + mp1[str[0]][c];
  }
  cout << sum;
  return 0;
}
