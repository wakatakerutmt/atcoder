#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;


int main() {

    /*
     * */
    int A, B;
    cin >> A >> B;

    rep(i,1000000){
        if(i*8/100 == A && i*10/100 == B){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}