#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;


/*
 * 文字列演算の時間計算量　文字列の長さを|S|とすると
 * ・先頭に文字を追加 O(|S|)
 * ・末尾に文字を追加 O(1)
 * ・反転(reverse) O(Q^2)
 *
 * 遅い → deque を使う
 *
 * */

int main() {

    /*
     * 問題文の通りに直接シミュレーションするだけでは反転クエリが高速に処理できず、 O((N + Q)^2)となり遅いです。
     * Ti = 1 のとき実際に文字列を操作するのではなく、現在どちら側が先頭かという情報を持っておけ
     * ば、Ti = 2 のクエリでもその情報を考慮することで、位置関係を保ったままシミュレーションできま
     * す。最後に全体を反転する必要がある場合に気をつけてください。
     * ここで、C + + などで普通の文字列型の先頭に追加する操作は計算量が悪いため、dequeue で文字
     * 列を管理するか、左右で分けて文字列を保持し最後に適切に連結するといった方法で対処できます
     * */

    string s;
    cin >> s;
    deque<char> q;
    for (char c : s) q.push_back(c);

    bool flip = false;
    int Q;
    cin >> Q;
    rep(qi, Q){
        int ty;
        cin >> ty;
        if(ty == 1){
            flip =!flip;
        }else{
            int f; char c;
            cin >> f >> c;
            if(flip) f = 3-f;
            if(f == 1){
                q.push_front(c);
            }else{
                q.push_back(c);
            };
        }
    }
    if(flip) reverse(q.begin(), q.end());
    string ans;
    for(char c : q) ans += c;
    cout << ans << endl;
    return 0;

    // 別解stackによるやり方　常に末尾に追加する
    /*
    string s;
    cin >> s;
    int q;
    cin >> q;
    string t;
    rep(qi, q){
        int ty;
        cin >> ty;
        if(ty == 1){
            swap(s,t);
        }else{
            int f; char c;
            cin >> f >> c;
            if(f == 1){
                t += c;
            }else{
                s += c;
            }
        }
    }

    reverse(t.begin(), t.end());
    t += s;
    cout << t << endl;
    return 0;
    */
}