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

int main() {

    string S;
    cin >> S;

    // 0スタート
    int count0 = 0;
    rep(i, S.size()){
        if(i % 2 ==  0 && S[i] != '0') {
            count0++;
        }else if(i % 2 ==  1 && S[i] != '1'){
            count0++;
        }
    }

    // 1スタート
    int count1 = 0;
    rep(i, S.size()){
        if(i % 2 ==  0 && S[i] != '1') {
            count1++;
        }else if(i % 2 ==  1 && S[i] != '0'){
            count1++;
        }
    }

    int res = 0;
    if(count0 > count1){
        res = count1;
    }else{
        res = count0;
    }
    cout << res << endl;
}