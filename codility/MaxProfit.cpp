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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;

using namespace std;

int solution(vector<int> &A) {
  int N = A.size();
  int minIndex = 0;
  long long ans = -1;
  for (int i = 0; i < N; i++) {
    if (A[minIndex] >= A[i]) {
      minIndex = i;
    }
    long long cur = A[i] - A[minIndex];
    ans = max(cur, ans);
  }

  return ans;
}

int main() {
  vector<int> c = {23171, 21011, 21123, 21366, 21013, 21367};
  cout << solution(c) << endl;
}