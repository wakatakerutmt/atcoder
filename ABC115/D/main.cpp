#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

long long rec(int n, long long x) {
    if (n == 0) return 1;
    long long len = (1LL<<(n+1)) - 3;
    long long num = (1LL<<n) - 1;
    if (x == 1) return 0;
    else if (x <= len + 1) return rec(n-1, x-1);
    else if (x == len + 2) return num + 1;
    else if (x <= (len + 1) * 2) return num + 1 + rec(n-1, x-len-2);
    else return num * 2 + 1;
}

int main() {
    int N; long long X;
    cin >> N >> X;
    cout << rec(N, X) << endl;
}