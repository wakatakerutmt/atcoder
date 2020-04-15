#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/* シンプルに基本操作：ソートによる簡易化手法 */
int main() {
    int N, K;
    cin >> N >> K;
    int h[N];
    rep(i, N) cin >> h[i];
    sort(h, h + N, greater<int>());

    int minD = INF;
    rep(i, N-K+1){
        if(minD > abs(h[i] - h[i+K-1])){
            minD = abs(h[i] - h[i+K-1]);
        }
    }
    cout << minD << endl;
}
