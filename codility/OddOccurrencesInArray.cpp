// https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)

int solution(vector<int> &A) {
    int N = A.size();
    
    unordered_map<int, int> m;
    rep(i, N) {
        m[A[i]]++;
    }
    
    for (auto kv : m) {
        if (kv.second % 2 == 1) {
            return kv.first;
        }
    }
    return 0;
}
