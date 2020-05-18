#include <iostream>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
int M[MAX][MAX]; // 隣接行列

// プリムのアルゴリズム　（最小全域木を求めるアルゴリズム）
int prim() {
    int u, mincost;
    int d[MAX]; // d[v]にTに属する頂点とV-Tに属する頂点をつなぐ辺の中で重みが最小の辺の重みを記録する
    int p[MAX]; // p[v]にMSTにおける頂点vの親を記録していきます。
    int color[MAX]; // color[v]にvの訪問状態を記録します。

    // 全部初期化
    for (int i = 0; i < n; ++i) {
        d[i] = INFTY;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0; //最初は頂点0から開始するための初期化

    while(1){
        // 初期化
        mincost = INFTY;
        u = -1;

        // 探索済みでない頂点のうち、最も小さい辺のコストを探す
        for (int i = 0; i < n; ++i) {
            if(mincost > d[i] && color[i] != BLACK){
                u = i;
                mincost = d[i];
            }
        }
        if(u == -1){ // 全部探索済みなら終了
            break;
        }

        // uを探索済みにする
        color[u] = BLACK;

        // uからvへ　このｖは最も辺のコストが小さいものを選ぶ
        for (int v = 0; v < n; ++v) {
            if(color[v] != BLACK && M[u][v] != INFTY){
                if(d[v] > M[u][v]){
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1){
            sum += M[i][p[i]];
        }
    }

    return sum;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int e;
            cin >> e;
            M[i][j] = (e==-1) ? INFTY: e;
        }
    }
    cout << prim() << endl;
    return 0;
}