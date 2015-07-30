#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
string s;
int dp[80010][11], N;

bool input(){
    cin >> s;
    if(s == "0") return 0;
    return 1;
}

int solve(){
    memset(dp, 0, sizeof(dp));
    N = s.size();
    rep(i,N) {
        int d = s[i]-'0';
        dp[i+1][d] = d > 0;
        rep(j,11) if(dp[i][j])
            dp[i+1][(10*j+d)%11] += dp[i][j];
    }
    int ans = 0;
    rep(i,N) ans += dp[i+1][0];
    return ans;
}

signed main(){
    while(input()){ cout << solve() << endl;}
    return 0;
}


