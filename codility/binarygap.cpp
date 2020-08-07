// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
using namespace std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> binary(0);
    while (N > 0) {
        binary.push_back(N % 2);
        N /= 2;
    }
    reverse(binary.begin(), binary.end());
    
    // count 0
    int lindex = 0;
    int ans = 0;
    
    for (int i = 0; i < (int)binary.size(); i++) {
        if (binary[i] == 1) {
            ans = max(ans, i - lindex - 1);
            lindex = i;
        }
    }
    return ans;
}