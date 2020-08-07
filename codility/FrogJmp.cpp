// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)

using namespace std;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    if (Y <= X) return 0;

    int diff = Y - X;
    int num = diff / D;
    if (diff % D != 0) {
        num += 1;
    }
    return num;
}