#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("sorts/quicksort.txt"); \
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

int pivot(vector<int>& c, int l, int r) {
  int i = l - 1;
  int pivot = c[r];

  for (int j = i + 1; j < r; j++) {
    if (c[j] < pivot) {
      i++;
      swap(c[i], c[j]);
    }
  }
  swap(c[i+1], c[r]);
  return i + 1;
}

void quickSort(vector<int>& c, int l, int r) {
  if (l < r) {
    int pivIndex = pivot(c, l, r);

    quickSort(c, l, pivIndex - 1);
    quickSort(c, pivIndex + 1, r);
  }
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  vector<int> c = {3, 5, 4, 6, 7, 9, 1, 2, 3};
  int n = c.size();

  quickSort(c, 0, n - 1);

  print_vec(c);
}