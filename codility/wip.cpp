#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.size();
    vector<int> ip(N);
    
    rep(i, N) {
        if (S[i] == 'A') ip[i] = 1;
        if (S[i] == 'C') ip[i] = 2;
        if (S[i] == 'G') ip[i] = 3;
        if (S[i] == 'T') ip[i] = 4;
    }
    
    int M = P.size();
    vector<int> ans(M);

    for (int i = 0; i < M; i++) {
        int p = P[i];
        int q = Q[i];
        int ret = 4;
        for (int j = p; j <= q; j++) {
            ret = min(ret, ip[j]);
        }
        ans[i] = ret;
    }
    return ans;
}