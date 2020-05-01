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

/*
 *  |S| のmaxが200000なので全探索のO(n^2)では間に合わない
 *  DPを使う
 *
 * 　今回は「2019と10が互いに素　gcd(2019,10)=1　」が重要、すなわち
 * 「10^x * n が2019の倍数の時、nも2019の倍数になっている」
 *
 * 　この問題のように、「連続する区間」についての問題では、"累積和的なもの" をとるのが定石
 * 通常、累積和は左側から考えるケースが多いけど、今回は右側から考える。
 *
 * 【解法】
 *  ・N 文字の文字列 S から、長さ N+1 の累積和 s[0], s[1], ..., s[N] を作る
    ・これを 2019 で割ったあまりで分類する (具体的には counter[ r ] := あまりが r のやつが何個あるか)
    ・各 r ごとに、counter[r] 個から 2 個選ぶ方法の数を、足し上げる

    計算量は、O(N)

 * */

int main() {

    string S;
    cin >> S;

    int N = S.size();
    vector<ll> val(2019, 0);
    ll fac = 1;
    ll cur = 0;
    val[cur]++;
    for (int i = 0; i < N; ++i) {
        ll add = S[N-1-i] - '0';
        cur = (cur + fac * add) % 2019;
        fac = (fac * 10) % 2019;
        val[cur]++;
    }
    ll res = 0;
    for (int i = 0; i < val.size(); ++i) {
        res += val[i] * (val[i] - 1) / 2;
    }

    cout << res << endl;
}