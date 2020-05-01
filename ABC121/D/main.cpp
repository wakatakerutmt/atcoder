#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする
template<class T> void chmin(T &a, T b){ if(a>b) a = b; }

// 二分探索 前方のindexを返すもの（自分自身を含む） 前方: -INF側のこと
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1; // upper_bound : keyより大きい要素の内の一番左側のイテレータを返す
}
// 二分探索 後方のindexを返すもの（自分自身を含む）後方: INF側のこと
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin(); // lower_bound : key以上の要素の内の一番左側のイテレータを返す
}

/*
 *  f(A, B) = f(0, B) ^ f(0, A-1) という分解ができる（累積和）
 *
 *  つまりf(0, N) を求めることができればOKとなる
 *  ただし、ループは10^12オーダーなので使えない何か別の方法を考える必要がある。
 *
 *  「任意の偶数とその次の奇数のXORは必ず1になる」という性質に着目します。
 *  これは偶数とその次の奇数を2進数で表した場合に、1bit目だけが異なることから明らかです。
 *
 *  f(0,N) = 0 ^ 1 ^ 2 ^ 3 ^ ... ^ N-1 ^ N
 *         = (0^1) ^ (2^3) ^ ... ^ N-1) ^ N  / または  (N-1^N)
 *         =   1   ^   1   ^     ^  1   ^ N  /           1
 *
 *   つまり 4 ずつ0が表れる周期的な動きになる
 *   Nを４で割った余りが
 *   　0の時: f(0,N) = N (4,8,12など)
 *     1の時: f(0,N) = 1
 *     2の時: f(0,N) = N ^ 1
 *     3の時: f(0,N) = 0
 *   となる
 * */

ll f(ll n){
    switch(n%4){
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n ^ 1;
        case 3:
            return 0;
    }
}

int main() {
    ll A, B;
    cin >> A >> B;

    ll res = f(A-1) ^ f(B);

    cout << res << endl;
}