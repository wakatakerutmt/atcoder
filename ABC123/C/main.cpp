#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする　大きい値にする
template<class T> bool chmin(T &a, T b){
    if(a>b) {
        a = b;
        return true;
    }
    return false;

}
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
 * 最大人数送り出すのを繰り返す貪欲法では10^15はTLEとなってしまうのでダメ
 *
 * 定員の人数が最も小さいところがボトルネックになることに着目する（人が詰まってしまう）
 *
 * すなわち
   ・最初の人がボトルネックに到達するまで
   ・ボトルネックを N 人分裁くまで
   ・最後にボトルネックが通過した人がゴールするまで
   を足したものが答えになる。1 と 3 は実は合計して必ず 4 になる。ちょっと色々試してみるとわかる。

   2 は、ボトルネックの定員を mi 人として、N を mi を割って余りを切り上げた値になる。その値は (N+mi−1)/mi になる。

 * */

int main() {

    ll N; cin >> N;
    vector<ll> A(5);
    ll mi = 1LL<<60;
    for (int i = 0; i < 5; ++i) cin >> A[i], mi = min(mi, A[i]);
    cout << (N + mi - 1) / mi + 4 << endl;
}