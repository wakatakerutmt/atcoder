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


// 素因数分解 pair
vector<pair<ll, ll> > prime_factorize(ll n) {
    vector<pair<ll, ll> > res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

const int MAX = 210000;
const int MOD = 1000000007;

//  二項係数の計算nCk セット
//  https://drken1215.hatenablog.com/entry/2018/06/08/210000
//  使い方としては、最初に一度前処理として COMinit() をしておけば、あとは COM(n, k) 関数を呼べばよい
//  前処理 COMinit(): O(n)
//　クエリ処理 COM(n, k): O(1)
ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int vector_finder(std::vector<int> vec, int number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
    if (index != vec.size()) { // 発見できたとき
        return 1;
    }
    else { // 発見できなかったとき
        return 0;
    }
}

typedef pair<int,int> pint;
typedef pair<pint,pint> ppint;

/*
 * 1. 全ての行について奇数の数を右にずらしていく
左から順番に見ていって、奇数の個数であれば、1つ左に移す。
移せば、移した元は偶数になる。
もし、移した先が奇数になってしまった場合は、続けてそれも右にずらしていこう。
これを繰り返すと、各行について最右以外は偶数にできる
　
2. 最右の列について奇数の数を下にずらしていく
上から順番に見ていって、奇数の個数であれば、1つ下に移す
移せば、移した元は偶数になる。
もし、移した先が奇数になってしまった場合は、続けてそれも下にずらしていこう。
これを繰り返すと、全体では右下以外は偶数にできる
 *
 * */

int main() {

    int H, W;
    cin >> H >> W;
    vector<vector<int> > a(H, vector<int>(W, 0));
    int odd = 0;
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
            if (a[i][j] & 1) ++odd;
        }

    vector<ppint> res;
    int num = 0;
    int x = 0, y = 0;
    for (int iter = 0; iter < W*H; ++iter) {
        if (a[x][y] & 1) ++num;

        int nx = x, ny = y;
        if (x % 2 == 0) {
            if (ny == W-1) ++nx;
            else ++ny;
        }
        else {
            if (ny == 0) ++nx;
            else --ny;
        }
        if (num & 1) if (num < odd) res.push_back(ppint(pint(x, y), pint(nx, ny)));
        x = nx, y = ny;
    }

    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first.first+1 << " " << p.first.second+1 << " " << p.second.first+1 << " " << p.second.second+1 << endl;
    }
}