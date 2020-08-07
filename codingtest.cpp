#ifdef LOCAL
#define INPUT_FILE                          \
  ifstream in("input.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
//start ------------

#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
const int INF = 100100100;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)

using namespace std;

int main() {
  INPUT_FILE
}