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
 *
 * 区間に対するフリップ操作に関する問題で考えると良さそうなこととして

    ・区間が互いに交差しないものとして扱えないか (他に区間の終端でソートして考えるなども)
    ・いもす法変換によって、区間に対する操作を 2 点に対する操作として扱えないか
 *
 *
 * 「0 の個数」と「1 の個数」を交互に書き出してみる。紛らわしさを防ぐために、
 * 両端が「1」じゃないならば、両端に「0 個の 1」があるものとみなして 0 を書いておく。すると
 *
    0, 2, 4, ... 番目の値は「連続する 1 の個数」
    1, 3, 5, ... 番目の値は「連続する 0 の個数」

    と考えることができ、「0, 2, 4, ... 番目から始まる連続する 2K+1 個 (以下) の整数の和の最大値」を求めればよい。
 * */

int main() {

    int N, K; cin >> N >> K;
    string S; cin >> S;

    // 「1 の個数」「0 の個数」を交互に記録していく
    vector<int> nums;
    if (S[0] == '0') nums.push_back(0); // 先頭が 0 だったら
    for (int i = 0; i < S.size();) {
        int j = i;
        while (j < S.size() && S[j] == S[i]) ++j; // S[i] の数値がどこまで続くか
        nums.push_back(j - i);
        i = j;
    }
    if (S.back() == '0') nums.push_back(0); // 最後尾が 0 だったら

    // 累積和
    vector<int> sums((int)nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); ++i) sums[i+1] = sums[i] + nums[i];

    // 偶数番目の添字から始まる、長さ 2K+1 (以下) の区間の総和のうち、最大値を求める
    int res = 0;
    for (int left = 0; left < sums.size(); left += 2) {
        int right = left + K*2+1;
        if (right >= sums.size()) right = (int)sums.size() - 1;
        res = max(res, sums[right] - sums[left]);
    }
    cout << res << endl;
}