#include <bits/stdc++.h>
using namespace std;
static const int N = 100;

// 隣接行列を作る

int main() {
    int M[N][N];
    int n, u, k, v;
    cin >> n;

    // 初期化
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j] = 0;
        }
    }

    // 入力を反映
    for (int i = 0; i < ; ++i) {
        cin >> u >> k;
        u--;

        for (int j = 0; j < k; ++j) {
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    // 出力
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(j) cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }

    return 0;
}