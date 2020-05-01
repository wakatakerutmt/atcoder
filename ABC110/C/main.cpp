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
 * 一対一対応の置換　⇒　map を使う
 *
 * 10^5なので O(N^2)では間に合わないO(N)である必要がある。
 *
 *
 * */


int main() {

    string S, T;
    cin >> S >> T;
    bool ok = true;
    map<char,char> ma, ima;
    for (int i = 0; i < S.size(); ++i) {
        char s = S[i], t = T[i];

        if (ma.count(s)) { // map.count(key) で keyがあれば1, なければ0を返す
                           // 条件：変換リストに登録されていて
            if (ma[s] != t) { //  一対一対応の変換リストに登録されているのと違う変換だったらダメ
                ok = false;
            }
        }
        if (ima.count(t)) {
            if (ima[t] != s) {
                ok = false;
            }
        }

        ma[s] = t; ima[t] = s; // 一対一の変換リストへの登録
    }
    if (ok) puts("Yes");
    else puts("No");

}