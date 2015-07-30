#include <cmath>
#include <iostream>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)

int K, R[1024];
double dp[16][1024];

void input(){
    cin >> K;
    rep(i,1<<K) cin >> R[i];
}

void solve(){
    rep(i,1<<K) dp[0][i] = 1.0;
    repi(i,1,K+1)rep(j,1<<K){
        int d = j >> (i - 1);
        int l, r;
        d -= 2 * (d % 2);
        l = (d + 1) << (i - 1);
        r = (d + 2) << (i - 1);
        repi(k,l,r)if(j != k) dp[i][j] += dp[i-1][j] * dp[i-1][k] / (1 + pow(10.0,1.0*(R[k]-R[j]) / 400.0));
    }
    rep(i,1<<K) printf("%.9f\n",dp[K][i]);
}

signed main(){
    input();
    solve();
    return 0;
}
