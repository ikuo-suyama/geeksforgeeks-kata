// キャッシュレジスター
// プログラミング チャレンジの説明:
// この課題では、キャッシュレジスター（レジ）のプログラムを設計します。2桁の十進数が与えられます。1つ目はアイテムの購入価格（Purchase
// Price: PP）です。2つ目は顧客が支払った現金（Cash: CH）です。
// 現在、レジの中には以下の紙幣と硬貨があります：

// 'PENNY': .01,
// 'NICKEL': .05,
// 'DIME': .10,
// 'QUARTER': .25,
// 'HALF DOLLAR': .50,
// 'ONE': 1.00,
// 'TWO': 2.00,
// 'FIVE': 5.00,
// 'TEN': 10.00,
// 'TWENTY': 20.00,
// 'FIFTY': 50.00,
// 'ONE HUNDRED': 100.00
// このプログラムの目的は、顧客にお釣りとして返すべき紙幣/硬貨を計算することです。

// 入力:
// 標準入力から行を読み込む必要があります。各行にはセミコロンで区切られた2つの数値が含まれています。1つ目は購入価格（PP）で、2つ目は顧客が支払った現金（CH）です。

// 出力:
// 入力の各行に対して、顧客に返すお釣りを出力します。CH<PPの場合、ERRORを出力します。CH==
// PPの場合、ZEROを出力します。その他のケースは、顧客に返すべきお釣りの金額に相当する紙幣/硬貨を出力します。なお、回答はアルファベット順にソートする必要があります。

// テスト 1
// テストの入力
// テスト 1 の入力をダウンロード
// 15.94;16.00
// 期待される出力
// テスト 1 の入力をダウンロード
// NICKEL,PENNY
// テスト 2
// テストの入力
// テスト 2 の入力をダウンロード
// 17;16
// 期待される出力
// テスト 2 の入力をダウンロード
// ERROR
// テスト 3
// テストの入力
// テスト 3 の入力をダウンロード
// 35;35
// 期待される出力
// テスト 3 の入力をダウンロード
// ZERO
// テスト 4
// テストの入力
// テスト 4 の入力をダウンロード
// 45;50
// 期待される出力
// テスト 4 の入力をダウンロード
// FIVE

#ifdef LOCAL
#define INPUT_FILE          \
  ifstream in("input.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
// start ------------
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
const int INF = 100100100;
using namespace std;


vector<string> calcChange(long long rest) {
  vector<string> ret(0);
  
  vector<string> name = {"PENNY" ,"NICKEL" ,"DIME" ,"QUARTER" ,"HALF DOLLAR" ,"ONE" ,"TWO" ,"FIVE" ,"TEN" ,"TWENTY" ,"FIFTY" ,"ONE HUNDRED"};
  vector<long long> amount = {1, 5, 10, 25, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
  
  reverse(name.begin(), name.end());
  reverse(amount.begin(), amount.end());
  
  int N = name.size();
  for (int i = 0; i < N; i++) {
    int n = rest / amount[i];
    if (n > 0) {
      for (int j = 0; j < n; j++) {
        ret.push_back(name[i]);
      }
      rest -= n * amount[i];
    }
  }
  
  sort(ret.begin(), ret.end());
  return ret;
}

vector<string> split(string target, char c) {
  int N = target.size();
  string left = "", right = "";
  for (int i = 0; i < N; i++) {
    if (target[i] == c) {
      left = target.substr(0, i);
      right = target.substr(i + 1, N - 1);
    }
  }
  return {left, right};
}

int main() {
  string line;
  cin >> line;
  int N = line.size();
  
  vector<string> splitted = split(line, ';');
  
  double purchase = stod(splitted[0]);
  double cash = stod(splitted[1]);
  
  if (left == right || purchase == cash) {
    cout << "ZERO" << endl;
    return 0;
  }
  if (purchase > cash) {
        cout << "ERROR" << endl;
    return 0;
  }
  
  
  long long lpurchase = purchase * 100;
  long long lcash = cash * 100;
  vector<string> ans = calcChange(lcash - lpurchase);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() -1) {
      cout << ',';
    }
  }
  return 0;
}