#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;


static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[N][N];
int color[N], d[N], f[N], tt;
int nt[N];

int next(int u) {
    for (int v = nt[u]; v < n; ++v) {
        nt[u] = v + 1;
        if(M[u][v]){
            return v;
        }
    }
    return -1;
}

void dfs_visit(int r){
    rep(i,n) nt[i]=0;

    stack<int> S;
    S.push(r);
    color[r] = GRAY;
    d[r] = ++tt;

    while(!S.empty()){
        int u = S.top();
        int v = next(u);
        if(v != -1){
            if(color[v] == WHITE){
                color[v] = GRAY;
                d[v] = ++tt;
                S.push(v);
            }
        }else{
            S.pop();
            color[u] = BLACK;
            f[u] = ++tt;
        }
    }
}

// 深さ優先探索
void dfs() {
    // 初期化
    rep(i,n){
        color[i] = WHITE; // 訪れていない
        nt[i] = 0;
    }
    tt = 0;

    // 未訪問のuを始点として深さ優先探索
    rep(u,n){
        if(color[u] == WHITE) dfs_visit(u);
    }
    rep(i,n){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }

}

int main() {
    int u, k , v;

    cin >> n;

    // 初期化
    rep(i,n) {
        rep(j,n){
            M[i][j] = 0;
        }
    }

    // 隣接行列の作成
    rep(i,n){
        cin >> u >>k;
        u--;
        for (int j = 0; j < k; ++j) {
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    dfs();
    return 0;
}

