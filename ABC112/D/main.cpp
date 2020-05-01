#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする　大きい値にする
template<class T> bool chmin(T &a, T b){ if(a>b) a = b; }
template<class T> void chmax(T &a, T b){ if(a<b) a = b; }

// 二分探索 前方のindexを返すもの（自分自身を含む） 前方: -INF側のこと
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1; // upper_bound : keyより大きい要素の内の一番左側のイテレータを返す
}
// 二分探索 後方のindexを返すもの（自分自身を含む）後方: INF側のこと
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin(); // lower_bound : key以上の要素の内の一番左側のイテレータを返す
}

// 最大公約数を求める GCD
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }


/*
 * dを最大公約数とすると d <= ai なので Nd <= M である
 *
 * よってまとめると答えは「M の約数 d のうち、Nd≤M を満たす最大のものになる。
 *
 *
 * 制約より、Mのとりうる最大値は109と大きいですが、M=ABとしたときの約数のペア(A, B)は高々√Mを境に対称なので、探索は√M以下までで十分です。
    対称というのはたとえば、M=100のとき、約数のペア(A, B)は、

    M = 1 * 100
    M = 2 * 50
    M = 4 * 25
    M = 5 * 20
    M = 10 * 10 (ここから対称)
    M = 20 * 5
    M = 25 * 4
    M = 50 * 2
    M = 100 * 1
    となるので、約数のペアを探すのに1~100まで探索しなくても、1~10までの探索でOKです。
 *
 * */

vector<ll> calc_divisor(ll m){
    vector<ll> res;
    for(ll i = 1LL; i*i <= m; i++){
        if(m % i == 0){
            res.push_back(i);
            ll j = m / i;

            if(j != i){
                res.push_back(j); // 約数のペアも格納
            }
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main() {

    ll N,M;
    cin >> N >> M;

    vector<ll> div = calc_divisor(M);

    // M の約数 d であって、d * N <= M となる最大の d を求める
    long long res = 1;
    for (auto d : div) {
        if (d * N <= M) res = max(res, d);
    }

    cout << res << endl;

}