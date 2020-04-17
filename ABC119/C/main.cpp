#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*
 *
 * 問題を細分化する
 *
 * 目的を達成するには
 * ⓵延長または短縮
 * ⓶合成
 * の操作が必要
 *
 * 注意したいのは「⓵と⓶の操作はどっちを先にしても結果は変わらない（操作順序の違いによる結果は不変）」
 *
 * 合成の必要がないものは、正解の数値との差＝MPのカウント数と一括で計算できる。
 * →最も数値の近いものを１つ選べばよい
 * 合成の必要があるのは正解の数値との差を直接魔法で埋めるより効率がいいとき（最も正解の数値と近くなる）
 * →二つや三つ選ぶこともある　→　この判断を適切に行うのは難しい
 *
 * ここでNは8までしかない。→　全探索を考えるのが吉
 *
 * また、最も近くなるような棒（数値）を1つ以上選べばよい問題と定義しなおせる（あとは正解の差を計算するだけなので）
 *
 * 棒を L[N] L[N-1] ... L[2]　L[1] L[0] と並べてそれぞれをビットに対応させるとA,B,Cがそれぞれどれを取るかを探索できる
 *       1     1                    1   Aがとる棒(n桁のビット列)
 *       0     0         1     0    0   Bがとる棒
 *       0     0         0     1    0   Cがとる棒
 *
 * このようにA,B,Cに関してforの三重ループで全探索できる。
 * そうして、選んだ棒と正解の数値との差が最も小さいものを探せばよいことになる
 * 同じ棒を選ばないようにだけ注意は必要
 *
 *
bit 全探索による方法
まず A に採用する竹を選んで
残りの中から B に採用する竹を選んで
その残りの中から C に採用する竹を選んで...
とする
 * */

int N;
vector<int> L;
vector<int> A; // A, B, C

int main() {
    cin >> N;
    A.resize(3);
    for (int i = 0; i < 3; ++i) cin >> A[i];
    L.resize(N);
    for (int i = 0; i < N; ++i) cin >> L[i];

    int res = 1<<29;
    vector<int> bit(3);
    for (bit[0] = 1; bit[0] < (1<<N); ++bit[0]) { // 0 は含めない
        for (bit[1] = 1; bit[1] < (1<<N); ++bit[1]) { // 0 は含めない
            // 共通要素あったらダメ
            if (bit[1] & bit[0]) continue;
            for (bit[2] = 1; bit[2] < (1<<N); ++bit[2]) { // 0 は含めない
                // 共通要素があったらダメ
                if (bit[2] & bit[0]) continue;
                if (bit[2] & bit[1]) continue;

                // sums: A〜C に選んだ竹の長さの合計、nums: A〜C に選んだ竹の本数
                vector<int> sums(3, 0), nums(3, 0);
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (bit[j] & (1<<i)) {
                            sums[j] += L[i];
                            nums[j]++;
                        }
                    }
                }

                // score を求める
                int score = 0;
                for (int i = 0; i < 3; ++i) {
                    score += abs(sums[i] - A[i]); // +1, -1 のコスト
                    score += (nums[i] - 1) * 10; // 合体のコスト
                }
                res = min(res, score);
            }
        }
    }
    cout << res << endl;
}