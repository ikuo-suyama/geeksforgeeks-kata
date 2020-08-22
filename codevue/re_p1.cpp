#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("codevue/re_p1.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

string _10to2(long long bin) {
  string ret = "";
  while(bin > 0) {
    ret += bin % 2 == 0 ? "0" : "1";
    bin /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string l, r;
  cin >> l >> r;

  if (l.size() < r.size()) {
    swap(l, r);
  }
  string s;
  for (int i = 0; i < l.size() - r.size(); i++) {
    s += "0";
  }
  r = s + r;

  int N = max(l.size(), r.size());
  vector<int> lv(N);
  vector<int> rv(N);
  for (int i = 0; i < N; i++) {
    lv[i] = l[i] - '0';
    rv[i] = r[i] - '0';
  }

  int next = 0;
  string ret = "";
  for (int i = N - 1; i >= 0; i--) {
    int cur = next + lv[i] + rv[i];
    if (cur >= 2) {
      next = 1;
      cur %= 2;
    } else {
      next = 0;
    }
    ret += cur == 0 ? "0" : "1";
  }
  if (next == 1) {
    ret += "1";
  }

  reverse(ret.begin(), ret.end());
  cout << ret << endl;
}