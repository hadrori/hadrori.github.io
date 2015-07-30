#include <algorithm>
#include <iostream>
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
using namespace std;

int A, B;
int a[1024], b[1024];
int suma[1024], sumb[1024];
int dp[1024][1024];

void input(){
    cin >> A >> B;
    rep(i,A) cin >> a[i];
    rep(i,B) cin >> b[i];
    reverse(a,a+A+1); reverse(b,b+B+1);
    repi(i,1,A+1) suma[i] += suma[i-1] + a[i];
    repi(i,1,B+1) sumb[i] += sumb[i-1] + b[i];
}

int solve(){
    rep(i,A+1) rep(j,B+1){
        if(i) dp[i][j] = max(dp[i][j], suma[i-1] + sumb[j] - dp[i-1][j] + a[i]);
        if(j) dp[i][j] = max(dp[i][j], suma[i] + sumb[j-1] - dp[i][j-1] + b[j]);
    }
    return dp[A][B];
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
