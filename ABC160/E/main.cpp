#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

int main() {

    /*
     * 赤色の個数をA個とり緑色の個数をB個、無色をC個取るとすると
     * X+Y = A+B+C ...⓵
     * A <= X ...⓶
     * B <= Y ...⓷
     * が条件
     *
     * １．X個大きい順から取る、Y個大きい順から取る、それ以外のものは消す（これで⓶⓷を常に満たすようにできる）
     * ２．すると、あとはその赤色と緑色と無色のものから好きに大きい順から取る
     * */

    int x, y;
    cin >> x >> y;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(p.rbegin(), p.rend()); // rはリバースでこれで降順になる
    sort(q.rbegin(), q.rend());
    vector<int> d;
    rep(i,x) d.push_back(p[i]);
    rep(i,y) d.push_back(q[i]);
    rep(i,c) d.push_back(r[i]);
    sort(d.rbegin(), d.rend());
    ll ans = 0;
    rep(i,x+y) ans += d[i];
    cout << ans << endl;
    return 0;
}

