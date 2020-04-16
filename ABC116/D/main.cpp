#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/* 「寿司の種類数xを固定する」という方針
 *  x種類の選び方は「『一番美味しい寿司』が美味しい方から貪欲に選ぶ」のが最適
 *
 *  x種類選ぶときの最善策は以下のような貪欲法となる。

    ・寿司を「その種類で一番美味しいもの」と「その他」に分ける。
    ・前者から、美味しい順にx個食べる。 (x種類の確保)
    ・後者から、美味しい順にK−x個食べる。
 * */

// priority_queueはソートが面倒だから使っているだけで、別にvectorをソートしても何ら問題はない。
int main() {
    int N, K;
    cin >> N >> K;
    int t[N], d[N];

    priority_queue<ll> kind[N];
    rep(i, N){
        int t;
        ll d;
        cin >> t >> d;
        kind[t-1].push(d);
    }

    priority_queue<ll> best, remain;
    // best: 各種類で一番おいしいやつを集めたもの
    // remain: bestのあまり
    rep(i, N){
        if(!kind[i].empty()){
            best.push(kind[i].top());
            kind[i].pop();

            while(!kind[i].empty()){
                remain.push(kind[i].top());
                kind[i].pop();
            }
        }
    }

    vector<ll> bsum = {0};
    // bestの累積和 (bsum[i] = bestの先頭からi個の総和)
    while (!best.empty()) {
        bsum.push_back(bsum.back() + best.top());
        best.pop();
    }

    vector<ll> rsum = {0};
    // remainの累積和
    while (!remain.empty()) {
        rsum.push_back(rsum.back() + remain.top());
        remain.pop();
    }

    ll ans = 0;
    for (ll x = 1; x <= K; ++x) {
        // 種類が多すぎるケース
        if (x >= bsum.size()) break;

        // 種類が少なすぎて、余り物が足りないケース
        if (K - x >= rsum.size()) continue;

        // bestからx個、remainからK-x個貪欲に選ぶ
        ans = max(ans, bsum[x] + rsum[K - x] + x * x);
    }

    cout << ans << endl;
    return 0;
}
