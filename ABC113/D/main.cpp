#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;
const int mod = 1000000007;
/*
 bit全探索 + DP


H = 100, W = 8 のケースで、あみだくじの個数は 34100 ≒ 1.4 ∗ 10153 個程度あり、全探索できない。
 ➡DPを使う
A(h, x) を、縦から h 列目を通過した (横棒を通った場合も含む) 直後に左から x 本目の縦棒に
いる場合の数とします。h = 0 のとき、1 列目より前を表すことにます。
h = 0, 1, 2, 3, …, H の順に上から下に降りていく感じで A(h, x) を更新していくことにします。
左から 1 本目の縦棒からスタートするので、A(0, 1) = 1、A(0, 2) = A(0, 3) = … = A(0, W) = 0
になります。
A(h, x) が指しているあみだくじの経路からは、A(h + 1, x − 1), A(h + 1, x), A(h + 1, x + 1) の
いずれかの状態に行くことになります。A(h, x) の状態から何通りが x − 1 本目の縦棒に行って、
何通りが x 本目の縦棒にとどまって、何通りが x + 1 本目の縦棒に行くかは、h + 1 本目の横棒
の配置を全探索することで計算することができます。先ほどの x − 1, x, x + 1 本目に行く場合の
数をそれぞれ X, Y, Z とおくと、A(h + 1, x − 1), A(h + 1, x), A(h + 1, x + 1) の結果はそれぞれ
X ∗ A(h, x), Y ∗ A(h, x), Z ∗ A(h, x) 足されることになります。
したがって、計算量 O(HW2W ) で解くことができます。H = 100, W = 8 のケースでも、十分
に間に合わせることができます。


*/
int main() {

    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<int> > dp(H + 1, vector<int>(W, 0)); dp[0][0] = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {

            /* bit 全探索 */
            for (int k = 0; k < 1 << (W - 1); ++k) {
                // Check if two horizontal lines are connecting
                // 2 つの横線がつながっていないか調べる
                bool ok = true;
                for (int l = 0; l < W - 2; ++l) {
                    if (((k >> l) & 1) && ((k >> (l + 1)) & 1)) {
                        ok = false;
                    }
                }

                /* DP */
                if (ok) {
                    if (j >= 1 && ((k >> (j - 1)) & 1)) {
                        // The case which goes left
                        // 左方向に横線をたどるケース
                        dp[i + 1][j - 1] += dp[i][j];
                        dp[i + 1][j - 1] %= mod;
                    }
                    else if (j <= W - 2 && ((k >> j) & 1)) {
                        // The case which goes right
                        // 右方向に横線をたどるケース
                        dp[i + 1][j + 1] += dp[i][j];
                        dp[i + 1][j + 1] %= mod;
                    }
                    else {
                        // The case which goes straight
                        // 横線をたどらないケース
                        dp[i + 1][j] += dp[i][j];
                        dp[i + 1][j] %= mod;
                    }
                }
            }
        }
    }
    cout << dp[H][K - 1] << '\n';
    return 0;
}
/* 別解 方針は同じ */

//const ll MOD = 1e9 + 7;
//
//int main() {
//    int H, W, K;
//    cin >> H >> W >> K;
//
//    --K;
//    // 以降縦棒の番号は0-indexedで扱う
//
//    ll dp[H + 1][W];
//    fill(dp[0], dp[H + 1], 0);
//    dp[0][0] = 1;
//    // dp[h][k] = 横線h段からなるあみだくじで、0がkに来るものの数
//
//    for (int h = 0; h < H; ++h) {
//        for (int b = 0; b < (1 << (W - 1)); ++b) {
//
//            // 横線が隣り合っていないかチェック
//            bool judge = true;
//            for (int i = 0; i < W - 2; ++i) {
//                // これで末尾が11のときに弾くことができる
//                if ((b >> i) % 4 == 3) judge = false;
//            }
//
//            if (!judge) continue;
//
//            // 各始点がどこへ移動するか求める
//            int perm[W];
//            for (int i = 0; i < W; ++i) perm[i] = i;
//
//            for (int i = 0; i < W - 1; ++i) {
//                // あみだくじのルールに従って位置をswap
//                if ((b >> i) & 1) swap(perm[i], perm[i + 1]);
//            }
//
//            // 配る
//            for (int i = 0; i < W; ++i) {
//                dp[h + 1][perm[i]] += dp[h][i];
//                dp[h + 1][perm[i]] %= MOD;
//            }
//        }
//    }
//
//    cout << dp[H][K] << endl;
//    return 0;
//}