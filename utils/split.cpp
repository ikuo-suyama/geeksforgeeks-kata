#include <fstream>
#ifdef LOCAL
#define INPUT_FILE             \
  ifstream in("utils/split.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
// start ------------

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
const int INF = 100100100;
using namespace std;

#define print_vec(v)                   \
  for (int l = 0; l < v.size(); l++) { \
    cout << v[l] << " ";               \
  }                                    \
  cout << endl;

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  return A.size();
}

vector<int> split(string target, char c) {
  target += c;
  int N = target.size();
  int bef = 0;
  vector<int> ret(0);
  for (int i = 0; i < N; i++) {
    if (target[i] == c) {
      string cur = target.substr(bef, i - bef);
      ret.push_back(stoi(cur));
      bef = i + 1;
    }
  }

  return ret;
}

int main() {
  INPUT_FILE

  string line;
  cin >> line;

  vector<int> c = split(line, ';');

  print_vec(c);
  cout << solution(c) << endl;
}