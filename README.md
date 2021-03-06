基本的な知識や参考になるリンクなど



### 上限値に対するオーダーの考える目安

N=10～15 (bit演算でO( (N^2) * (2^N))ぐらいまで許容)   
N=50 (ありうる全てのパターンを全探索)    
N=1000～2000 ( O(N^2) )    
N=10^5 ( O(N) )    
N=10^9 ( O(log N)にする方法を考える )    

`1 秒間で処理できる for 文ループの回数は、10^8回程度`  

### オーダーの抑え込みの手法

O(n^2) ⇒O(n) : 尺取り法, DP   
O(n^3) ⇒O(nlogn) : 優先度キュー, DP      
   


### 頻度の高い利用関数チートシート

| 処理内容 | 関数名、式など | 具体例 |
| ---- | ---- | ---- |
| string型からint型へ変換 | stoi() | stoi("1234") // 1234  | 
| string型のスライス | string.substr(開始位置, 文字数) | "1234".substr(1,2) // "23" | 


### 文字列の扱い

着眼点  
・prefixだけでなく、suffixから見る方法ではどうか


### 基本思想

着眼点   
・条件となる数式を列挙  
・制約条件を簡単にできる方法はないか   
・制約条件が緩いときは全探索や貪欲法でいけないか      

### 【 全探索 】

| アルゴリズム | 時間計算量 | 使う場面 |
| ---- | ---- | ---- |
| 深さ優先DFS | O(E) | 状態の遷移が分岐するような処理 |
| 幅優先探索BFS | O(E) | 列挙がメイン、探索なら途中で切る必要がある |

https://pyteyon.hatenablog.com/entry/2019/03/01/211133   
```
example: 「DFS」再帰による実装法

int dfs(int pos, ~~~) {
    // ⓵停止条件
    // ⓶再帰の分岐処理
    // 任意の停止条件を書く
    if (pos == N) return ~~~;

    // pos を進めながら（末端に進みながら）分岐処理
    // 末端まで到達した時それぞれの分岐から値が返される
    // for 文で書ける場合は for 文で実装
    int ret1 = dfs(pos + 1, 分岐 1);
    int ret2 = dfs(pos + 1, 分岐 2);
    int ret3 = dfs(pos + 1, 分岐 3);
    ...

    // それぞれの分岐からの戻り値の処理を行う関数
    return func(ret1, ret2, ret3);
}
```

```
example: 「BFS」queueによる実装法

struct Object {
    // 任意の構造体
    ll hoge;
    ...
    ll depth;
}

queue<int> q;
Object start = {~~~, 0};  // 深さ 0
q.push(start);  // 初期状態をキューに入れる

int bfs() {
    while (!q.empty()) {
        // キューの先頭の要素を取り出す dequeue(pop)
        Object now = q.front(); q.pop();

        // 停止条件
        // if (now.hoge == target) return ~;  // 探索対象
        if (now.hoge == N) return ~;

        // BFS
        for (int i = 0; i < 次のノード（状態）の数; ++i) {
            Object next = {~~~, depth+1};  // 深さ（ステップ数）を一つ足す
            if (条件) {
                // 条件を満たしたら enqueue(push)
                // 問題により，同じ状態に戻らないようにする処理を書く（無限ループを防ぐ）
                q.push(next);
            }
        }
    }
}
```

### 【 Bit演算・探索 】

着眼点
・桁や集合に着目する


| アルゴリズム | 時間計算量 | 使う場面 |
| ---- | ---- | ---- |
| Bit全探索 | 2^n | n(桁数や要素数が 30以下などの制約がある場合) |
| Bit部分集合探索 | 2^m (m<n) | 部分集合の要素数mでの探索 |


良く使う表   

| 用途 | 式 | 使う場面 |
| ---- | ---- | ---- |
| ビット bit に i 番目のフラグが立っているかどうか  |  if(bit & (1<<i))  | Bit全探索/一部のチェック |
| 全探索の上限  |  bit < (1<<n) | for文の条件式 |
| 部分集合の更新式 | bit = (bit-1) & A(A:部分集合) | for文のBit更新式 |
   
   
https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361    


### 【 貪欲法 】

K個取るという条件のもとで、色々な制約条件からスコアの合計値が一番大きいものを求める題のとき、   
一番大きい数字から取っていく手法   
   
・配列のソートが面倒なときは `priority_queue<int>` を使うと楽になる   
・ある種類の中で、大きい値からいくつ取るかを逐一計算するのは時間がかかるので`累積和`との相性が良い   

   
   
      
### 【 動的計画法 】

1つ前の値から更新するものという先入観はなくすこと。

・dp[i] = max(dp[i-1] + ~~ , dp[i-2] + ~~ )  // 一つや二つごとに更新できるDP    
・dp[i]+~~ → dp[i+k], dp[i]+~~ → dp[i+l]   // 現時点からいくつか先を更新していくDP   

と、柔軟に考える必要がある場合も多い     


### 【 桁DP 】
・非負整数 X が X≤K の範囲を動くときの、〜〜〜の最大値を求めよ     
・非負整数 X が X≤K の範囲を動くときの、〜〜〜という条件を満たすものは何通りあるか   

dp[i][smaller]  i: i桁目,  smaller: Kと一致するか否かの「未満フラグ」で行う   
格納する値はその時点の最大値など    
●dpの流れ   
 * ⓪初期化   
 * ⓵初期条件を代入する  
 * ⓶逐次代入   

https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab

### 【 グラフ 】
Nを頂点数 Mを辺数 便宜上N<=M として考える  
  
最短経路問題


| アルゴリズム | 時間計算量 | 使う場面 |
| ---- | ---- | ---- |
|  BFS  |  O(N+M) = O(M)  | 辺のコストが全部1 |
|  ダイクストラ  |  O(N+MlogM) = O(MlogM) または O(N-2+M) | 辺のコストが0以上 |
|  ワーシャルフロイド  |  O(N^3)  | 密なグラフ(Mが多い)で実装が軽い(制約が緩い) <br> 全点間の最短距離が欲しい時。(BFSならO(NM)になるためMが多い場合は有利) |
|  ベルマンフォード  |  O(NM)  | 負のコストの辺がある |
