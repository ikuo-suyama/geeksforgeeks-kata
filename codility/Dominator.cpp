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
    unordered_map<int, int> counter;
    int N = A.size();
    rep(i, N) {
        counter[A[i]]++;
        if(counter[A[i]] > N / 2) {
            return i;
        }
    }
    return -1;
}

int main() {
  // vector<int> c = {1, 0, 1};
  vector<int> c = {1, 5, 2, 1, 4, 0};
  cout << solution(c) << endl;
}