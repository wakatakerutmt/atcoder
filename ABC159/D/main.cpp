#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector <int> A(n,0);
    vector <int> B(n+1,0);
    for(int i=0;i<n;i++){
        cin >> A[i];
        B[A[i]]++;
    }
    int sum=0;
    for(int i=0;i<n+1;i++){
        sum+=(B[i]*(B[i]-1))/2;
    }
    vector<int> C(n,0);
    for(int i=0;i<n;i++){
        C[i]=sum-B[A[i]]*(B[A[i]]-1)/2+(B[A[i]]-1)*(B[A[i]]-2)/2;
        cout << C[i] << endl;
    }
    return 0;
}

//    sort(A, A + N, greater<int>()); 降順