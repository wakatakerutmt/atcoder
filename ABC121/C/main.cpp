#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする
template<class T> void chmin(T &a, T b){ if(a>b) a = b; }

// 二分探索 前方のindexを返すもの（自分自身を含む） 前方: -INF側のこと
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1; // upper_bound : keyより大きい要素の内の一番左側のイテレータを返す
}
// 二分探索 後方のindexを返すもの（自分自身を含む）後方: INF側のこと
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin(); // lower_bound : key以上の要素の内の一番左側のイテレータを返す
}

/*
 * pair配列の扱い
 * */

int main() {

    int N;
    ll M;
    cin >> N >> M;
    vector<pair<ll, ll>> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());  // Vectorの要素がPairの時のsort時の挙動は、
                                //    -一つ目を昇順にソートする。
                                //    -一つ目が同一の場合はさらに二つ目を昇順にソートする。
                                // これを反対にしたい場合は greater<spair<ll, ll>>() を第三引数に加える

    ll res = 0;
    for (int i = 0; i < N && M > 0; ++i) {
        res += v[i].first * min(M, v[i].second);
        M -= min(M, v[i].second);
    }
    cout << res << endl;
}