#ifdef LOCAL
#define INPUT_FILE          \
  ifstream in("input.txt"); \
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

#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;


int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  return A.size();
}

int main() {
  vector<int> c = {1, 2, 3};
  cout << solution(c) << endl;
}