#include <fstream>
#ifdef LOCAL
#define INPUT_FILE             \
  ifstream in("utils/whilein.txt"); \
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

int main() {
  INPUT_FILE

  vector<string> inputs;
  string buf;
  while (cin >> buf) {
    inputs.push_back(buf);
  }

  print_vec(inputs);

  vector<int> c(0);
  cout << solution(c) << endl;
}