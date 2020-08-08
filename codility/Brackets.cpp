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
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stack>
const int INF = 100100100;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#define print_vec(v) \
rep(l, v.size()) { cout << v[l] << " "; } \
cout << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> nested;
    int N = S.size();
    rep(i, N) {
      char cur = S[i];
      if (cur == '{' || cur == '[' || cur == '(') {
        nested.push(cur);
      } else {
        if (nested.size() == 0) return 0;
        char b = nested.top();
        nested.pop();
        if ((b == '{' && cur != '}') || (b == '(' && cur != ')') ||
            (b == '[' && cur != ']')) {
          return 0;
        }
      }
    }
    if (nested.size() == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
  string c = ")(";
  cout << solution(c) << endl;
}