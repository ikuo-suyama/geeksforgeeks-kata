

#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    sort(A.begin(), A.end());

    int bef = 0;
    rep(i, N) {
        if (A[i] < 1) continue;
        if (A[i] > bef + 1) return bef + 1;
        else bef = A[i];
    }
    return bef + 1;
}
