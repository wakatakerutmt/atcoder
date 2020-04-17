#include <bits/stdc++.h>
using namespace std;


/*
 *
 * LCS (最長共通部分列：Longest Common Subsequence) とは，2つの文字列 X[1,...,m] , Y[1,…,n] において、
 * 双方に現れる部分文字列の中で最長の文字列と定義されています。部分列は連続している必要はありませんが，順序を変更してはいけません。
   例えば、「東京工芸大学」と「京橋工業芸術大学」のLCSは「京工芸大学」で、長さは5です。

 * http://www.cs.t-kougei.ac.jp/SSys/LCS.htm
 * */

const int N = 1000;

int lcs(string X, string Y){

    int c[N+1][N+1];
    int xlen = X.size();
    int ylen = Y.size();

    int maxl = 0;

    X = " " + X; // 空白を先頭に加えておくという前処理をするのがポイント‼‼
    Y = " " + Y;

    for(int i= 1; i <= xlen; i++) c[i][0] = 0;
    for(int i= 1; i <= ylen; i++) c[0][i] = 0;

    for(int i= 1; i <= xlen; i++) {
        for(int j= 1; j <= ylen; j++) {

            if( X[i] == Y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
            }else{
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }

            maxl = max(maxl, c[i][j]);
        }
    }

    return maxl;
}



int main() {

    string s1, s2;
    int n;

    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> s1 >> s2;
        cout << lcs(s1,s2) << endl;
    }

    return 0;
}