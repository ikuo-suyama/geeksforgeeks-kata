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
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int X = 0, Y = 1, Z = 2;
    int ans = 0;
    int current = 0;
    int xtoy = 0;
    while(Z < N - 1) {
        current += A[Z];
        Z++;

        if(A[Y] > A[Z-1]) {
            int befY = Y;

            Y = Z - 1;
            current += A[befY];
            current -= A[Y];
            for (int i = befY; i < Y; i++) {
                xtoy += A[i];
            }
            
            if (-xtoy >= A[befY]) {
                current -= xtoy;
                current -= A[befY];
                X = befY;
                xtoy = 0;
            }
        }
        ans = max(current, ans);
    }
    
    return ans;
}

int main() {
  // vector<int> c = {3, 2, 6, -1, 4, 5, -1, 2};
  vector<int> c = {-2, -3, -4, 1, -5, -6, -7};
  cout << solution(c) << endl;
}