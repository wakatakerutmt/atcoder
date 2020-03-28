#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;


int c[10][1005]; // 2次元配列

int main() {

    /*
     * 1≤H≤10
     * 1≤W≤1000
     * でHが小さいのがポイント
     * 全探索で横向きに切って切り方は2^H で縦に切っていけばO(2^H * W)
     * 貪欲法
     * */

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    // <<はシフト演算子 1<<3は3bit左にシフトするので1000=8となる
    // 従って 1<<k は 2^kを表す
    int ans = INF;
    rep(div,1<<(h-1)){
        int g = 0; // グループ数を表す
        vector<int> id(h);
        rep(i,h){
            id[i] = g;
            if(div>>i&1) { // シフトした後に1との&
                ++g;
            }
        }
        ++g;
        rep(i,g)rep(j,w) c[i][j] = 0;
        rep(i,h)rep(j,w) c[id[i]][j] += (s[i][j]-'0'); // 文字型から数字型へ変換 '1' - '0' = 1になる（1文字の時のみ使える）

        int num = g-1; // 横で切った数　次から縦で切るのを考える
        vector<int> now(g);
        auto add = [&](int j) {
            rep(i,g) now[i] += c[i][j];
            rep(i,g) if(now[i] > k) false;
            return true;
        };
        rep(j,w){
            if(!add(j)) {
                num++;
                now = vector<int>(g);
                if(!add(j)){
                    num = INF;
                    break;
                }
            }
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
    return 0;
}


/*
https://drken1215.hatenablog.com/entry/2020/03/23/002300
https://www.hamayanhamayan.com/entry/2020/03/22/231629
勉強させていただいた記事
*/

//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//typedef long double ld;
//typedef pair<ll, ll> pll;
//
//const ll LongINF=1e13+7;
//const int INF=1e9+7;
//const int dx[]={0,1,0,-1};
//const int dy[]={1,0,-1,0};
//
//template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
//template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
//template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
//void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない
//
//using vi=vector<int>;
//using vii=vector<vi>;
//
//#define REP(i,a,b) for(int i=(a);i<(b);i++)
//#define rep(i,n) REP(i,0,n)
//#define pb push_back
//#define rv reverse
//#define ALL(a) (a).begin(),(a).end()
//#define decimal(x) fixed<<setprecision(x)
//
//
//int main(){
//    int H,W,K,res=1<<29;
//    cin>>H>>W>>K;
//    vector<string> S(H);
//    rep(i,H)cin>>S[i];
//    for(int bit=0;bit<(1<<(H-1));bit++){
//        bool gok=true;
//        int N=0;
//        vi ord(H,0);//横線において、区切る物をcoする累積和を行うことで、面積分けをしている。
//        rep(i,H-1){
//            if(!(bit&(1<<i)))ord[i+1]=ord[i];
//            else ord[i+1]=ord[i]+1,++N;
//            //cout<<"ord:"<<ord[i+1]<<" N:"<<N<<" ";
//        }
//        //cout<<endl;
//        int add=0;
//        vi nums(N+1,0);
//        rep(i,W){//縦ごとのカウント
//            vi one(N+1,0);
//            bool ok=true;
//            rep(j,H){
//                //ord[j]とすることで、横線の単位では異なっていても、同じエリアということでカウントできる。
//                one[ord[j]]+=S[j][i]-'0';
//                nums[ord[j]]+=S[j][i]-'0';
//                if(one[ord[j]]>K)gok=false;
//                if(nums[ord[j]]>K)ok=false;
//                //cout<<"j:"<<j<<" one:"<<one[ord[j]]<<" nums:"<<nums[ord[j]]<<" ";
//            }/*
//            cout<<i<<endl;
//            cout<<"one :";
//            for(auto x:one)cout<<x<<" ";
//            cout<<endl<<"nums:";
//            for(auto x:nums)cout<<x<<" ";
//            cout<<endl;
//            */
//            //oneでは縦列のみのカウントだが、numsでは、Kを超えるまでのカウントを保持している。
//            //そのため、K>one[ord[j]] の時nums=oneでリセットしている。
//            if(!ok)++add,nums=one;
//        }
//        if(gok)chmin(res,N+add);
//    }
//
//    cout<<res<<endl;
//
//    return 0;
//}

//a=97,z=122