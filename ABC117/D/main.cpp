#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*
 * 桁DP
 * ・非負整数 X が X≤K の範囲を動くときの、〜〜〜の最大値を求めよ
 * ・非負整数 X が X≤K の範囲を動くときの、〜〜〜という条件を満たすものは何通りあるか
 * の時に有効
 *
 * dp[i][smaller]  i: i桁目,  smaller: Kと一致するか否かの「未満フラグ」
 * 格納する値はその時点の最大値など
 *
 * dpの流れ
 * ⓪初期化
 * ⓵初期条件を代入する
 * ⓶逐次代入
 *
 * XOR は a ^ b の演算でできる
 *
 * */
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const int MAX_DIGIT = 50; // とりあえず50桁までと決めて行う
long long dp[100][2]; // dp[上から i 桁まで][ smaller ]

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    memset(dp, -1, sizeof(dp)); // DP 配列を -1 で初期化

    dp[0][0] = 0; // 初期条件


    for (int d = 0; d < MAX_DIGIT; ++d) {
        long long mask = 1LL<<(MAX_DIGIT - d - 1);

        // A で元々 d 桁目にビットが立っているものの個数
        int num = 0;
        for (int i = 0; i < N; ++i) if (A[i] & mask) ++num;

        // X の d 桁目を 0, 1 にしたときのコスト
        long long cost0 = mask * num;
        long long cost1 = mask * (N - num);

        // smaller -> smaller
        if (dp[d][1] != -1) {
            chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1)); // 0 でも 1 でも自在に大きい方
        }

        // exact -> smaller
        if (dp[d][0] != -1) {
            if (K & mask) { // K の d 桁目が 1 だったら、X の d 桁目は 0 にする
                chmax(dp[d+1][1], dp[d][0] + cost0);
            }
        }

        // exact -> exact (K にぴったり合わせる)
        if (dp[d][0] != -1) {
            if (K & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
            else chmax(dp[d+1][0], dp[d][0] + cost0);
        }
    }
    cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
}