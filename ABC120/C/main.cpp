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
 * 解法１・・・()カッコ列の整合性判定問題の亜種として、スタックで処理
 *
 *　スタック st を用意する
    文字を順番に見て

    + '(' ならば st に push する
    + ')' のとき
      + st が空、または st.top が ')' なら push する
      + st.top が ')' なら pop してペアにする

    こうして作れるペアの個数が最大


    解法２・・・もっとシンプルに考えることができる。今回の問題では、まずはそもそも

        どんなに頑張っても min(0 の個数、1 の個数) 回より多く操作を行うことはできない
        ということがすぐにわかる。なぜなら、1 回の操作で必ず 0 と 1 を 1 個ずつ消すからだ。そしてなんと、
        逆に必ず min(0 の個数、1 の個数) 回の操作を達成できることが示せてしまう。
        こういう風に「自明な上界として考えた値が実は最適解」というのはよくある。

        さて、このような操作を扱う問題では

        「操作を行った結果出来上がるものがどんなものか、わかりやすく言い換える」

        を考察するのが良さそう。
        今回は
        「限界まで操作を行ったならば、最終結果に 0 と 1 が両方登場することはない」
        という事が言える
 * */


int main() {

    string s;
    cin >> s;

    int res = 0;
    stack<char> st;
    rep(i, s.size()){
        if(st.empty() || st.top() == s[i]){
            st.push(s[i]);
        }
        else{
            res += 2; // ペアを足す
            st.pop();
        }
    }
    cout << res << endl;

    /*  解法２ */
    /*
    string s;
    cin >> s;
    int zero =0, one =0;
    rep(i,s.size()){
        if(s[i]=='0') zero++;
        else one++;
    }
    cout << min(zero, one) * 2 << endl;
    */
}