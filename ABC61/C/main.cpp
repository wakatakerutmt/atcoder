#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*
 bit全探索
 ビット演算

 (1<<n) ＝2^n (全探索)


*/
int main() {

    string s;
    cin >> s;
    int n = s.size();
    ll sum = 0;
    for(int bit = 0; bit < (1 << (n - 1)); bit++){
        ll cur = 0;
        for(int i = 0; i < n; i++){
            cur = cur * 10 + (s[i] - '0');
            if(bit & (1 << i)){
                sum += cur;
                cur = 0;
            }
        }
        sum += cur;
    }
    cout << sum << endl;
    return 0;
}