#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)

const int mod = 10007;
int N;
string str;
int p[1024];

void input(){
    cin >> N;
    cin >> str;
    rep(i,N) p[i] = str[i]=='J'? 1: str[i]=='O'? 2: 4;
}

int dp[1024][8];

int solve(){
    dp[0][1] = 1;
    rep(i,N) rep(j,8) if(p[i] & j)
        rep(k,8) if(j & k){
            dp[i+1][j] += dp[i][k];
            dp[i+1][j] %= mod;
        }
    int ans = 0;
    rep(i,8){
        ans += dp[N][i];
        ans %= mod;
    }
    return ans;
}

int main(){
    input();
    cout << solve() << endl;
    return 0;
}
