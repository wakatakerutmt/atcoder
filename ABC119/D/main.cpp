#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

/*
 *
 * 最適解は以下のいずれかの形であることはわかる

    まずいずれかの「神社」を訪れて、そこから最も近い「寺」に訪れる
    まずいずれかの「寺」を訪れて、そこから最も近い「神社」に訪れる
    ここで、1 個目の場合について、最初に訪れる神社が必ずしも初期位置から最も近い位置がよいわけではないことに注意する。なぜなら、初期位置から最も近い神社に行っても、そこから最寄りの寺がすごく遠いかもしれない！！！！！！！！

    しかしそれでも、

    初期位置から前方の最寄りの神社
    初期位置から後方の最寄りの神社
    以外を狙う意味はないことがわかる。何故なら、これら以外の神社に行こうと思うと、「前方最寄り」「後方最寄り」のうちのいずれか一方には既に通りかかることになるからだ。

    というわけで初回の行動は以下の 4 パターンで、2 回目の行動はそこから最寄りの「寺」か「神社」に行けばよい。

    最初に前方最寄りの神社に行く
    最初に後方最寄りの神社に行く
    最初に前方最寄りの寺に行く
    最初に後方最寄りの寺に行く
 *
 * */


// aを常に小さい値にする
template<class T> void chmin(T &a, T b){
    if(a>b) a = b;
}

// 二分探索 前方のindexを返すもの（自分自身を含む） 前方: -INF側のこと
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1; // upper_bound : keyより大きい要素の内の一番左側のイテレータを返す
}
// 二分探索 後方のindexを返すもの（自分自身を含む）後方: INF側のこと
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin(); // lower_bound : key以上の要素の内の一番左側のイテレータを返す
}

int main() {

    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B);
    rep(i,A) cin >> s[i];
    rep(i,B) cin >> t[i];

    // 二分探索は配列外の目盛にアクセスする場合はあるので、番兵をいれておく
    s.push_back(INF); s.push_back(-INF); sort(s.begin(), s.end());
    t.push_back(INF); t.push_back(-INF); sort(t.begin(), t.end());

    rep(_,Q) {
        ll x;
        cin >> x;

        // かかる距離を保持する変数 resultの略
        ll res = INF;

        // 最初に s に訪れる（前方にいくか、後方に行くかで場合分け）
        for (int i = 0; i < 2; ++i) {
            ll first;
            if(i){
                first = s[former(s,x)];
            }else{
                first = s[latter(s,x)];
            }
            // 次に t (現在地の前後を調べて近い方に行く)
            for (int j = 0; j < 2; ++j) {
                ll second;
                if(j){
                    second = t[former(t,first)];
                }else{
                    second = t[latter(t,first)];
                }
                chmin(res, abs(x-first) + abs(first - second));
            }
        }

        // 最初に s に訪れる（前方にいくか、後方に行くかで場合分け）
        for (int i = 0; i < 2; ++i) {
            ll first;
            if(i){
                first = t[former(t,x)];
            }else{
                first = t[latter(t,x)];
            }
            // 次に t (現在地の前後を調べて近い方に行く)
            for (int j = 0; j < 2; ++j) {
                ll second;
                if(j){
                    second = s[former(s,first)];
                }else{
                    second = s[latter(s,first)];
                }
                chmin(res, abs(x-first) + abs(first - second));
            }
        }
        cout << res << endl;
    }
}