#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE           \
  ifstream in("dp/fib.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

vector<int> memo(10 + 1, INF);

int fib(int n) {
  if (n == 1) return 1;
  if (n < 1) return 0;
  if (memo[n] != INF) return memo[n];
  return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;
  cout << fib(10) << endl;
}