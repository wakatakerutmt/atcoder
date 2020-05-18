#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int> > adj[MAX]; // 重み付き有効グラフの隣接リスト表現

// O((|V|+|E|)log|V|) 隣接リストと二分ヒープ（優先度付きキュー）による実装
void dijkstra() {
    priority_queue<pair<int, int> > PQ;
    int d[MAX];
    int color[MAX];

    // 初期化
    for (int i = 0; i < n; ++i) {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    // 0番目を始点とする
    d[0] = 0;
    color[0] = GRAY;
    PQ.push(make_pair(0,0));

    while(!PQ.empty()){
        // 初期化(次の最も小さいコストのものを取得)
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;

        // uを探索済みにする
        color[u] = BLACK;

        // 最小値を取り出し、それが最短でなければ無視
        if(d[u] < f.first*(-1)){
            continue;
        }

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            if(color[v] == BLACK){
                continue;
            }
            if(d[v] > d[u] + adj[u][i].second){
                d[v] = d[u] + adj[u][i].second;
                // priprity_queueはデフォルトで大きい値を優先するため-1をかける
                PQ.push(make_pair(d[v]*(-1), v));
                color[v] = GRAY;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << i << " " << ( d[i] == INFTY ? -1: d[i]) << endl;
    }
}

// 単一始点最短経路　
//　これを求めるための有名なアルゴリズムがダイクストラ

int main() {

    cin >> n;

    int k, c, u, v;
    for (int i = 0; i < n; ++i) {
        cin >> u >> k;

        for (int j = 0; j < k; ++j) {
            cin >> v >> c;
            adj[u].push_back((make_pair(v,c)));
        }
    }

    dijkstra();

    return 0;
}