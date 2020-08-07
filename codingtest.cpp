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
#define print_vec(v) \
rep(l, v.size()) { cout << v[l] << " "; } \
cout << endl;

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
}

int main() {
  INPUT_FILE
}