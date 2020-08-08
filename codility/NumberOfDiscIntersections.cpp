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
    long ans = 0;
    
    vector<long> lefts(N);
    rep(i, N) {
        lefts[i] = i - A[i];
    }
    sort(lefts.begin(), lefts.end());
    
    rep(i, N - 1) {
        long l = i - A[i];
        long r = i + A[i];
       
        auto del = lower_bound(lefts.begin(), lefts.end(), l);
        // erase はO(N)やぞ
        // lefts.erase(del);
        lefts[del - lefts.begin()] = lefts.back();
        lefts.pop_back();

        int idx = upper_bound(lefts.begin(), lefts.end(), r) - lefts.begin();
        ans += idx;

        // repi(j, i + 1, N) {
        //     int tl = j - A[j];
        //     int tr = j + A[j];
        //     if (r >= tl) {
        //         ans++;
        //     }
        // }
        if (ans > 10000000) return -1;
    }
    return ans;
}

int main() {
  // vector<int> c = {1, 0, 1};
  vector<int> c = {1, 5, 2, 1, 4, 0};
  cout << solution(c) << endl;
}