#include <iostream>
#include <string>
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
const int inf = 1LL << 60;

using namespace std;

string s, ans;
int K;
int dp[1000010][30]; //i文字目以降でjから始まる部分文字列の数

void input(){ cin >> s >> K; }

void recover(int pos, int first, int L){
    //pos以降で一番左側の文字が未確定
    if(first == -1){
        rep(i,26){
            /*
              はじめの文字iを辞書順に見ていって, 初めてLを超えるのを探す.
              超えなければその文字から始まる部分文字列はまるまる無視するので
              Lからその数を引く.
            */
            if(L <= dp[pos][i]){
                recover(pos,i,L);
                return;
            }
            L -= dp[pos][i];
        }
    }
    //一致するまでposを下げる. 一致する文字は必ず存在する.
    while(s[pos] != 'a' + first) pos++;
    ans += s[pos];
    if(L > 1) recover(pos+1, -1, L-1);
}

string solve(){
    repd(i,s.size()-1,0) rep(j,26){
        if(s[i] == j + 'a'){
            dp[i][j] = 1;
            rep(k,26) dp[i][j] = min(dp[i][j]+dp[i+1][k],inf);
        }
        else dp[i][j] = dp[i+1][j];
    }
    int sum = 0;
    rep(i,26) sum = min(sum+dp[0][i],inf);
    if(K > sum) return "Eel";
    ans = "";
    recover(0, -1, K);
    return ans;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
