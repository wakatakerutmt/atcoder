#include <bits/stdc++.h>
using namespace std;
//using ll long long;
//#define int long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)


const int INF = 1001001001;

// 最短経路問題のアルゴリズム Nを頂点数 Mを辺数 N<=M として考える  使う場面
// BFS              : O(N+M)      = O(M)         　　　　      :   辺のコストが全部１
// ダイクストラ       : O(N+MlogM)  = O(MlogM)またはO(N-2+M)    :   辺のコストが色々（ただし全部正）
// ワーシャルフロイド  : O(N^3)                                 :   密なグラフ(Mが多い)で実装が軽い(制約が緩い)
// 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　全点間の最短距離が欲しい。(BFSならO(NM)になる)
// ベルマンフォード    : O(NM)                                  :   負のコストの辺がある

int main() {

    // N<=2000なのでO(n^2)ぐらいはOK
    // BFSを使って最短経路
    int n, x, y;
    cin >> n >> x >> y;
    --x; --y; // １からだと扱いにくいので0からにする

    // グラフを陽に持たない
    vector<int> ans(n);
    rep(sv, n){
        vector<int> dist(n, INF);
        queue<int> q;

        // [&]でキャプチャは参照とする（デフォルトで環境にある変数を参照して、ラムダ式のなかで使用する）
        auto push = [&](int v, int d){
            if(dist[v] != INF) return; //探索済み
            dist[v] = d;
            q.push(v);
        };
        push(sv, 0);
        while(!q.empty()) {
            int v = q.front(); q.pop(); // front : queue の最初の要素への参照。 pop : 最初の要素を除去して詰める
            int d = dist[v];
            if(v-1 >= 0) push(v-1, d+1);
            if(v+1 < n) push(v+1, d+1);
            if(v == x) push(y, d+1);
            if(v == y) push(x, d+1);
        }
        rep(i,n) ans[dist[i]]++;
    }
    rep(i,n) ans[i] /= 2;

    for (int i = 1; i <= n-1; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}

