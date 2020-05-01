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
 *  問題の条件は

    "AGC"
    "GAC"
    "ACG"
    "A＊GC" ( ＊は任意)
    "AG＊C" ( ＊は任意)
    のいずれも含まないことと言い換えられる。こういう禁止文字列系の問題は最悪 trie 木で直近文字列の遷移状態を管理するような DP でできる
    (蟻本に載ってる) が、ここでは

    「直近 3 文字がわかっていれば、それより前の文字列の情報は要らない」

    ということによって、簡単な DP でできる。

    dp[ n ][最後の前の前の文字][最後の前の文字][最後の文字] := 長さ n の文字列が何通り作れるか
    とした。文字として

    0: dammy (DP を初期化するのにこれがあると便利)
    1: A
    2: G
    3: C
    4 : T
    の 5 種類を割り当てた。dammy を用意すれば初期条件を
    dp[0][0][0][0] = 1
    と表せる
 * */

// mod add
const int MOD = 1000000007;
void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

// 多次元 vector 生成
// https://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}


int main() {
    int N; cin >> N;

    auto dp = make_vec<long long>(N+1, 5, 5, 5); // dp[i文字][3文字前][2文字前][1文字前]


    dp[0][0][0][0] = 1; // 初期化

    // 0: dammy, 1: 'A', 2: 'G', 3: 'C', 4: 'T'
    // "AGC, GAC, ACG", "A*GC", "AG*C" を含まない (012, 102, 021 を禁止)
    for (int n = 0; n < N; ++n) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    for (int l = 1; l < 5; ++l) {
                        if (i == 1 && j == 2 && l == 3) continue;
                        if (i == 1 && k == 2 && l == 3) continue;
                        if (j == 1 && k == 2 && l == 3) continue;
                        if (j == 2 && k == 1 && l == 3) continue;
                        if (j == 1 && k == 3 && l == 2) continue;
                        add(dp[n+1][j][k][l], dp[n][i][j][k]);
                    }
                }
            }
        }
    }

    long long res = 0;
    for (int i = 1; i < 5; ++i)
        for (int j = 1; j < 5; ++j)
            for (int k = 1; k < 5; ++k)
                add(res, dp[N][i][j][k]);

    cout << res << endl;
}