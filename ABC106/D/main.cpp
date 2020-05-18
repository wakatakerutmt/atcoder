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

/*
 * 二次元累積和　いもす法
https://tqk.hatenablog.jp/entry/ABC106-2
 *
 * */

int main() {

    int N, M, Q;
    cin >> N >> M >> Q;
    int l, r;
    //区間[l,r]を走る列車について考える。これを二次元平面上の(y座標,x座標)=(l,r)
    //の点とみなすとこの列車を完全に含むような区間はy<=lかつr<=xの範囲全てになる
    int imos[550][550];//imos[y][x]でyからxまでの区間に含まれる列車の本数
    for (int i = 0; i < 550; ++i) {
        for (int j = 0; j < 550; ++j) {
            imos[i][j] = 0;
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> l >> r;
        imos[l][r]++;
    }
    for (int i = 510; i >0; --i) {
        for (int j = 0; j <510; ++j) {
            imos[i - 1][j] += imos[i][j];
        }
    }
    for (int i = 0; i < 510; ++i) {
        for (int j = 0; j < 510; ++j) {
            imos[i][j + 1] += imos[i][j];
        }
    }
    for (int i = 0; i < Q; ++i) {
        cin >> l >> r;
        cout << imos[l][r] << endl;
    }
}