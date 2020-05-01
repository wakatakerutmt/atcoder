#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする　大きい値にする
template<class T> void chmin(T &a, T b){
    if(a>b) {
        a = b;
    }
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
 *
 * 　操作は結局何をしているのか簡単に言い換えられるかかが大事！！
 *
 * マイナスが偶数個だったらマイナス全部消せる
   マイナスが奇数個だったらマイナスが 1 個だけ残る この際一番絶対値が小さいところにマイナスをつければ OK

 * */

int main() {

    int N;
    cin >> N;
    ll A[N];
    rep(i,N) cin >> A[i];

    int num_minus = 0;
    ll mi = 1LL<<60;
    ll sum = 0;

    rep(i,N){
        if(A[i] < 0){
            num_minus++;
        }
        chmin(mi, abs(A[i]));
        sum += abs(A[i]);
    }

    if (num_minus % 2 == 0) cout << sum << endl;
    else cout << sum - mi*2 << endl;
}