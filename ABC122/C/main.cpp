#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする　大きい値にする
template<class T> void chmin(T &a, T b){ if(a>b) a = b; }
template<class T> void chmax(T &a, T b){ if(a<b) a = b; }

// 二分探索 前方のindexを返すもの（自分自身を含む） 前方: -INF側のこと
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1; // upper_bound : keyより大きい要素の内の一番左側のイテレータを返す
}
// 二分探索 後方のindexを返すもの（自分自身を含む）後方: INF側のこと
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin(); // lower_bound : key以上の要素の内の一番左側のイテレータを返す
}

/*
 *  ループの中で同じ計算をしているなと思ったら　➡　累積和でいけないか考える
 * */

bool check(char c1, char c2){
    return (c1 == 'A' && c2 == 'C');
}

int main() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    // 最初の文字からN文字目までのACの数を累積和として求めておく
    int sum[S.size()];
    rep(i, S.size()){
        sum[i] = 0; // 初期化
    }
    rep(i, S.size()) {
        if(i == 0) continue;
        if(S[i-1] == 'A' && S[i] == 'C'){
            sum[i] = sum[i-1] + 1;
        }else{
            sum[i] = sum[i-1];
        }
    }

    rep(i,Q) {
        unsigned l, r;
        cin >> l >> r;
        int res = sum[r-1] - sum[l-1];
        cout << res << endl;
    }
}