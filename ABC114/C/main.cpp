#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/* ⓵再帰な全探索　深さ優先探索（DFS）
 *
 * Nが10^9と大きく愚直な全探索ではきつい
 * 357の数字列があるものでNを超えないようなものを調べていくとよい
 * 9桁なので、それぞれの桁が3 or 5 or 7の場合を全て調べても3^9で済む。
 * 樹形図というか根つき3分木を考えるとわかりやすい
 * */

// 入力
long long N;

// cur: 現在の値、use: 7, 5, 3 のうちどれを使ったかを表すビット, counter: 答え
void func(long long cur, int use, long long &counter){
    if (cur > N) return; // ベースケース
    if (use == 0b111) ++counter; // 答えを増やす

    // 7 を付け加える
    func(cur * 10 + 7, use | 0b001, counter);

    // 5 を付け加える
    func(cur * 10 + 5, use | 0b010, counter);

    // 3 を付け加える
    func(cur * 10 + 3, use | 0b100, counter);
}

int main() {
    cin >> N;
    long long res = 0;
    func(0, 0, res);
    cout << res << endl;
}

/*　ちょっと別解

ll N;
int ans = 0;
void dfs(ll x,int a,int b,int c){
    if(x>N) return;
    if(a&b&c)ans++;
    dfs(10*x+3,1,b,c);
    dfs(10*x+5,a,1,c);
    dfs(10*x+7,a,b,1);
}

int main() {
    cin>>N;
    dfs(0,0,0,0);
    cout<<ans<<endl;
}

 */