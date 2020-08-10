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

    int X = 0, Y = 1, Z = 2;
    while(Z < N - 1) {
        Z++;
        repi(x, 0, Z - 2) {
            repi(y, x + 1, Z - 1) {
                int cur = 0;
                repi(i, x, Z) {
                    if(i != x && i != y) {
                        cur += A[i];
                    }
                }
                // printf("cur:%d / %d %d %d\n", cur, x, y, Z);
                ans = max(ans, cur);
            }
        }
    }
    
    return ans;
}

int main() {
  // vector<int> c = {3, 2, 6, -1, 4, 5, -1, 2};
  vector<int> c = {5, 17, 0, 3};
  cout << solution(c) << endl;
}