#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("sorts/heapsort.txt"); \
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

void makeHeap(vector<int>& c, int n, int root) {
  int largest = root;
  int l = root * 2;
  int r = root * 2 + 1;
  if (l < n && c[largest] < c[l]) largest = l;
  if (r < n && c[largest] < c[r]) largest = r;

  if (root != largest) {
    swap(c[root], c[largest]);
    // up-heap
    makeHeap(c, n, largest);
  }
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  vector<int> c = {3, 5, 4, 6, 7, 9, 1, 2, 3};
  int n = c.size();

  // make c heap
  for (int i = n / 2 - 1; i >= 0; i--) {
    makeHeap(c, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap(c[0], c[i]);
    // 入れ替えたところだけ再Heap化
    makeHeap(c, i, 0);
  }

  print_vec(c);
}