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

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.size();
    vector<int> ip(N);
    
    rep(i, N) {
        if (S[i] == 'A') ip[i] = 1;
        if (S[i] == 'C') ip[i] = 2;
        if (S[i] == 'G') ip[i] = 3;
        if (S[i] == 'T') ip[i] = 4;
        // cout << ip[i];
    }
    
    int M = P.size();
    vector<int> ans(M);

    vector<vector<int>> lmax(N, vector<int>(4, -1));
    vector<vector<int>> rmax(N, vector<int>(4, INF));
    
    lmax[0][ip[0]] = 0;
    repi(i, 1, N) {
        rep(j, 4) {
            if (ip[i] == j + 1) lmax[i][j] = i;
            else lmax[i][j] = lmax[i-1][j];
        }
    }
    
    rmax[N - 1][ip[N - 1]] = N - 1;
    for (int i = N - 2; i >= 0; i--) {
        rep(j, 4) {
            if (ip[i] == j + 1) rmax[i][j] = i;
            else rmax[i][j] = rmax[i+1][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        int p = P[i];
        int q = Q[i];
        int ret = 4;
        // for (int j = p; j <= q; j++) {
        //     ret = min(ret, ip[j]);
        // }

        auto llim = lmax[q];
        auto rlim = rmax[p];
        rep(j, 4) {
            // printf("-- j:%d / %d %d\n", j + 1, llim[j], rlim[j]);
            if (p <= llim[j] && rlim[j] <= q) {
                ret = j + 1;
                break;
            }
        }
        ans[i] = ret;
    }
    return ans;
}