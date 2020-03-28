#include <bits/stdc++.h>
using namespace std;
//using ll long long;
//#define int long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)

int main() {

    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    a.push_back(a[0]+k); // 円環は数直線に展開する（2kに伸ばしてやる）0をまたぐ部分を追加

    int l = 0;
    rep(i,n) {
        l = max(l, a[i+1]-a[i]);
    }
    int ans = k-l;
    cout << ans << endl;
    return 0;
}
