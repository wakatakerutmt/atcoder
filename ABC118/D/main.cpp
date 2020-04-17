#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*
 *  桁数が大きいほど大きい数になるので、桁数を大きくしたいが
 *  N本使うという制約があるため、貪欲法ではできない。
 *  ➡　動的計画法を使う(i <= i-1 のような一つずつの遷移とか限らない事に注意したい)
 *
 *  dp[ i ] := マッチ棒を i 本使って作れる数値の最大値
    とする。これに対し、各 a = A1,A2,…,AM に対して、
    chmax(dp[ i + match[ a ] ], dp[ i ] の末尾に "a" を加えたもの)
    という感じの遷移を実施すれば OK。match[ a ] は a を作るのに必要なマッチ棒の本数を表す。
 * */

long long match[10] = {2,5,5,4,5,6,3,7,6};
string dp[11000];
const string MINUSINF = "-";

void chmax(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}

int main() {
    int N, M; cin >> N >> M;
    int A[M];
    for (int i = 0; i < M; ++i) cin >> A[i];

    // 初期化
    rep(i,11000) dp[i] = MINUSINF;

    // 初期条件
    dp[0] = "";

    // DP ループ
    for (int i = 0; i <= N; ++i) {
        if (dp[i] == MINUSINF) continue;
        rep(j,M) {
            chmax(dp[i+match[A[j]-1]], dp[i] + (char)('0' + A[j]));
        }
    }
    cout << dp[N] << endl;
    return 0;
}
