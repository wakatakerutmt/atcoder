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
     長さ nn の数列 a1,a2,…,ana1,a2,…,an において

    ●「条件」を満たす区間 (連続する部分列) のうち、最小の長さを求めよ
    ●「条件」を満たす区間 (連続する部分列) のうち、最大の長さを求めよ
    ●「条件」を満たす区間 (連続する部分列) を数え上げよ

    ⇒　「尺取り法」が使える

    https://qiita.com/drken/items/ecd1a472d3a0e7db8dce

    「連続した０の区間の個数は、区間に対して単調増加する」ので尺取り法が使える

    【ポイント】
    ・右端ｒが１から０に移り変わるとき、連続した０の区間の個数contは１増える。
    ・左端ｌが０から１に移り変わるとき、連続した０の区間の個数contは１減る。
    ・一番左の部分が０から始まる場合、cont=1で始めないといけない。
    （理由：contが増えるのは左端が１から０に増えるときだが、一番左より左には文字はない。）
 * */

int main() {

    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    int ans = 0, r = 0, cont = 0;

    if (s[0] == '0') cont++;

    for (int l = 0; l < N; l++) {

        while (cont <= K && r < N) {
            if (r + 1 < N && s[r] == '1' && s[r + 1] == '0') cont++;
            r++;
        }

        ans = max(ans, r - l);

        if (l + 1 < N && s[l] == '0' && s[l + 1] == '1') cont--;
    }

    cout << ans << endl;
}