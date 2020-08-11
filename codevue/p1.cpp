// 二進数の加算
// プログラミング チャレンジの説明:
// 文字列として表される2つの二進数が与えられた時に、その合計値を二進数で出力するプログラムを作成します。 入力の各行にはコンマで区切られた2つの二進数の文字列が含まれています。 回答の先頭にはゼロを含めないでください。 回答がゼロの場合、ゼロを1つだけ出力します。つまり、出力は”0”になります。

// 入力:
// 標準入力から行を読み込む必要があります。各行にはコンマで区切られた2つの二進数の文字列が含まれています（各行の文字列はスペースを含みません）

// 出力:
// それぞれの行に含まれる二進数のペアに対して、それらを足し合わせた結果を出力してください。

// テスト 1
// テストの入力
// テスト 1 の入力をダウンロード
// 110011,1010
// 期待される出力
// テスト 1 の入力をダウンロード
// 111101
// テスト 2
// テストの入力
// テスト 2 の入力をダウンロード
// 11010,00101001
// 期待される出力
// テスト 2 の入力をダウンロード
// 1000011

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
const int INF = 100100100;
using namespace std;

long long _2to10(string s) {
  int N = s.size();
  reverse(s.begin(), s.end());
  long long ret = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] - '0' == 1) {
      ret += pow(2, i);
    }
  }
  return ret;
}

string _10to2(long long bin) {
  string ret = "";
  while(bin > 0) {
    ret += bin % 2 == 0 ? "0" : "1";
    bin /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  string line;
  cin >> line;
  int N = line.size();
  
  string left = "", right = "";
  for (int i = 0; i < N; i++) {
    if (line[i] == ',') {
      left = line.substr(0, i);
      right = line.substr(i + 1, N - i);
    }
  }
  
  // stringのまま計算するのは大変そうなのでいったんlong long に落とす
  long long l = _2to10(left);
  long long r = _2to10(right);
  
  long long sum = l + r;
  string ans = _10to2(sum);
  cout << ans << endl;
}