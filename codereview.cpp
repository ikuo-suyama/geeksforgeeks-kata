#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  vector<int> a = {1, 2, 3};
  vector<int> b = {1, 2, 3};

  set<vector<int>> s;
  s.insert(a);
  s.insert(b);
  // cout << s.size() << endl;
  int sum = 0;
  cout << (sum == -sum) << endl;

  set<pair<int, int>> s2;
  s2.insert(make_pair(1, 2));
  s2.insert(make_pair(1, 2));
  s2.insert(make_pair(2, 1));
  cout << s2.size() << endl;

  unordered_map<int, set<int>> m;
  set<int> s3 = {1};
  m[1] = s3;

  cout << m.count(0) << endl;
  cout << m.count(1) << endl;
}