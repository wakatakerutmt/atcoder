#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*
 *  N個の駒を距離が大きいところを潰すようにおくと
 *  M-(N-1)個の残りの距離を移動すればよい
 *
 * */
int main() {
    int N, M;
    cin >> N >> M;
    int X[M];
    rep(i, M) cin >> X[i];
    sort(X, X+M);

    // 各距離を計算
    int d[M-1];
    rep(i, M-1) d[i] = abs(X[i+1] - X[i]);

    // 駒の方が多いとき
    if(N >= M){
        cout << 0 << endl;
        return 0;
    }

    // 距離のうち駒の数だけ最長距離をつぶすので
    // 距離の短い順からM-1-(N-1)までだけ足したらOK
    sort(d, d+ M-1);
    int totalD = 0;
    rep(i, M-1-(N-1)){
        totalD += d[i];
    }
    cout << totalD<< endl;
    return 0;
}
