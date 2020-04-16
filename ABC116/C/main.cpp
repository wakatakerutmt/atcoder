#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

//「花の高さをhiから0に減らす」として考えることにする。
// 「左端の花から順に0にしていく」という方針で実装
int main() {
    int N;
    cin >> N;

    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    int ans = 0;
    // l : h[i] > 0なる最小のi
    for (int l = 0; l < N; ++l) {
        while (h[l] > 0) {
            int r;
            for (r = l + 1; r < N; ++r) {
                if (h[r] == 0) break;
            }
            // 区間[l, r)は全て正
            // この区間に対して水やりをする
            for (int x = l; x < r; ++x) --h[x];
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}

/* 愚直な実装 */
//int main() {
//    int N;
//    cin >> N;
//    int h[N];
//    rep(i, N) cin >> h[i];
//
//    int maxHeight = 0;
//    rep(i, N) {
//        if(maxHeight < h[i]){
//            maxHeight = h[i];
//        }
//    }
//
//    int count = 0;
//    int left, right;
//    rep(nowHeight, maxHeight){
//
//        left = -1;
//        rep(j, N){
//            if(h[j] > nowHeight && left == -1){
//                left = j;
//            }
//
//            if(h[j] <= nowHeight && left != -1){
//                right = j-1;
//                count++;
//                left = -1;
//            }
//            else if(j == N-1 && left != -1){
//                count++;
//            }
//        }
//    }
//    cout << count << endl;
//    return 0;
//}
