#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*
 *  最大公約数を求める
 *  ユークリッドの互除法
 * */

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N;
    int A[100001];
    cin >> N;
    rep(i,N) {
        cin >> A[i];
    }
    int ans = gcd(A[0], A[1]);
    for(int i=2; i<N; ++i) {
        ans = gcd(ans, A[i]);
    }
    cout << ans << endl;
    return 0;
}
