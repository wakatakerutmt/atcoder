#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

#define MAX 2000000

int N, A[MAX+1];

void maxHeapify(int i){
    int left, right, largest;
    left = 2*i;
    right = 2*i+1;

    // 左の子、自分、右の子で値が最大のノードを選ぶ
    if(left <= N && A[left] > A[i]) largest = left;
    else largest = i;
    if(right <= N && A[right] > A[largest]) largest = right;

    if(largest != i){
        swap(A[i], A[largest]);
        maxHeapify(largest); // 上に（根の方向に）上げていく
    }
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i]; // 添え字は1からスタートする
    for(int i = N/2; i >= 1; i--) maxHeapify(i); // 開始は 要素の半分からで良い N/2

    // 出力
    for(int i = 1; i <= N; i++) cout << " " << A[i];
    cout << endl;
    return 0;
}