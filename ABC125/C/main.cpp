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
// loopで書くなら
/*
 * int gcd(int a, int b){
 *     int r;
 *     while( (r = a % b) != 0 ) {
                a = b;
                b = r;
       }
       return b;
 * }
 *
 * */

/*
 * 複数の最大公約数に関して　前提知識として配列[a,b,c]のgcdはgcd(gcd(a,b),c)であることは知っておこう
 * つまり、累積和を用いる
 *
 * 問題は「N 個の値の中から 1 個だけ取り除いた N−1 個の整数の最大公約数の最大値を求める」こととなる
 *
 * つまり i番目を除いた、最大公約数を求めて、i:0->Nまで動かして最大公約数の最大を取ればよい
 * i番目を除いた最大公約数を累積和(累積GCDといった方が正確)を求めておく
 *
 * この際にA1, A2, ... Ai-1, Ai, Ai+1, ... An-1
 *        -------①--------     ------②-------
 *  ①と⓶の部分のGCDを求めておくと、楽にできる
 *
 *  left[p] := 区間 [0,p) の最大公約数
 *  right[p] := 区間 [p,N) の最大公約数
 *
 *  こうしておけば、

    前処理: O(NlogA)
    集計: O(NlogA)

    で求められる


    ----------------------なぜ右からの累積 GCD も必要か----------------------------
    今回の問題が累積 GCD じゃなくて、累積和だったなら、実は

    right[p] := 区間 [p,N) の累積和
    は要らなくて、

    left[p] := 区間 [0,p) の累積和
    だけで OK。これで区間 [l,r) の和は

    left[r]−left[l]
    で求められるのだ。だが今回の累積 GCD には「 - 」に対応する機能がない。引き算ができない。よって、区間 [p,N) についての GCD を求めるには右からの累積 GCD が必要になる。
 *
 * */

int main() {

    int N;
    cin >> N;
    int A[N];
    rep(i,N) cin >> A[i];

    // 累積GCD
    vector<int> left(N+1, 0);
    vector<int> right(N+1, 0);
    for (int i = 0; i < N; ++i) {
        left[i+1] = GCD(left[i], A[i]);
    }
    for (int i = N-1; i >= 0; --i) {
        right[i] = GCD(right[i+1], A[i]);
    }
    // 集計
    int res = 0;
    for (int i = 0; i < N; ++i) {
        // 左側
        int l = left[i];

        // 右側
        int r = right[i+1];

        // 更新
        chmax(res, GCD(l, r));
    }
    cout << res << endl;
}