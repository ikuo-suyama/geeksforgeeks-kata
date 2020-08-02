#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a[5] = {1, 2, 3, 4, 4};
  int b[5];
  memset(b, 0, 5 * sizeof(int));

  vector<int> c(5);
  vector<int> d = {1, 2, 3, 4, 5};

  for (int i = 0; i < 5; i++) {
    printf("%d %d %d %d\n", a[i], b[i], c[i], d[i]);
  }
}