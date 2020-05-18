#include <iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
int M[MAX][MAX];  // 隣接行列


// O(|V|^2) これは隣接行列（隣接リスト）のときのオーダーでこれは遅い
void dijkstra() {
    int mincost;
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

    while(1){
        // 初期化
        mincost = INFTY; //ここもINFTYにしていることでd[i]がINFTYなところは↓のループで探索されない
        int u = -1;

        // 最小コストの行先を取得
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

        // u→vの経路で、最短経路の場合更新
        for (int v = 0; v < n; ++v) {
            if(color[v] != BLACK && M[u][v] != INFTY){
                if(d[v] > d[u] + M[u][v]){
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j] = INFTY;
        }
    }

    int k, c, u, v;
    for (int i = 0; i < n; ++i) {
        cin >> u >> k;

        for (int j = 0; j < k; ++j) {
            cin >> v >> c;
            M[u][v] = c;
        }
    }

    dijkstra();

    return 0;
}