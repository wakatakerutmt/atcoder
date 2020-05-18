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
 * 「配列連続する区間」は、「累積和をとった配列上の 2 点」と同一視することができるという超頻出視点
 * A[left, right) が M の倍数
⇔ S[right] - S[left] が M の倍数
⇔ S[right] と S[left] を M で割ったあまりが等しい

 A の累積和配列 S を考える (スタートの「0」を忘れないように)
 S の各要素について M で割った余りで分類し、各余りについて何個あるのかを計上する
 (ただし M <= 10^9 なので、登場しうる余りが高々 N+1 個であることを利用して連想配列なりを用意する)
 各余りについて個数を p としたとき、p(p-1)/2 を加算する(同じ値の数から 2 つ選ぶときの組み合わせの個数が解になります。)

 *
 * */

int main() {

    int N, M;
    cin >> N >> M;

    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    map<ll, ll> nums;
    ll sum = 0;
    nums[sum]++;

    rep(i,N){
        sum += A[i];
        nums[sum % M]++;
    }

    ll res = 0;
    for(map<ll, ll>::iterator it = nums.begin(); it != nums.end(); ++it){
        res += it->second * (it->second - 1) / 2;
    }
    cout << res << endl;
}