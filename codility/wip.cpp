#ifdef LOCAL
#define INPUT_FILE          \
  ifstream in("input.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
using namespace std;
// start ------------

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

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

int solution(vector<int> &A) {
    int N = A.size();
    int ans = 0;
    rep(i, N) {
        int l = i - A[i];
        int r = i + A[i];
        
        repi(j, i + 1, N) {
            int tl = j - A[j];
            int tr = j + A[j];
            if (j <= r || r >= tl) {
                printf("j: %d %d %d\n", j, tr, tl);
                ans++;
            }
        }
        printf("%d %d\n",i,ans);
    }
    
    return ans;
}

int main() {
  vector<int> c = {1, 5, 2, 1, 4, 0};
  solution(c);
}