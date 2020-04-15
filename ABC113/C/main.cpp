#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;


// データ構造
// pair
//        pair型は2つの値の組を表す
// pair<値1の型, 値2の型> 変数名;で宣言する
//        変数名.firstで1番目の値、変数名.secondで2番目の値にアクセスできる
// make_pair(値1, 値2)でpairを生成することができる
//        tie(変数1, 変数2) = pair型の値;でpairを分解することができる
//        tuple

// tuple型は複数個の値の組を表す
// tuple<値1の型, 値2の型, 値3の型, (...)> 変数名;(必要な分だけ型を書く)で宣言する
//        make_tuple(値1, 値2, 値3, (...))でtupleを生成することができる
//        tie(変数1, 変数2, 変数3, (...)) = tuple型の値;でtupleを分解することができる

// pair/tupleの比較
//        1番目の値から比較され、等しい場合は次の値で比較される

// auto
//        変数宣言や範囲for文において、autoを用いることで、型を省略して書くことができる
//        autoで参照を作ることもできる

int main() {

    int N, M;

    cin >> N >> M;

    tuple<int, int, int> data[M]; // (Y_i, P_i, i)の配列

    rep(i, M){
        int p, y;
        cin >> p >> y;
        data[i] = make_tuple(y, p, i);
    }

    // tupleをソートするときは第一要素がkeyとなる
    // つまりY_iによって昇順にソートされる
    sort(data, data + M);

    int cnt[N + 1];
    fill(cnt, cnt + N + 1, 0); // 配列に全て同じ値を代入するfill
    // 各県に今属している市の数

    pair<int, int> id[M];
    // 各市の(属する県、県の中で誕生した順番)

    for (int i = 0; i < M; ++i) {
        int y, p, idx;
        tie(y, p, idx) = data[i]; // tieでtupleを分解
        ++cnt[p];
        id[idx] = make_pair(p, cnt[p]);
    }

    for (int i = 0; i < M; ++i) {
        // setwで文字数、setfillで埋める文字を指定
        // iomanipをincludeする必要があるので注意
        cout << setw(6) << setfill('0') << id[i].first;
        cout << setw(6) << setfill('0') << id[i].second << endl;
    }

    return 0;
}