#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int inf = 1e9, M = 200001;
int N, a[32];
double dp[32][M];
inline double f(int x, int y){ return 1.*abs(x-y)/x;}

double solve(){
    rep(i,N) fill(dp[i],dp[i]+M,inf);
    repi(i,1,M) dp[0][i] = f(a[0],i);
    
    rep(i,N-1) repi(j,1,M) if(dp[i][j] < inf) for(int k = j; k < M; k += j)
        dp[i+1][k] = min(dp[i+1][k], max(dp[i][j], f(a[i+1],k)));
    double ans = inf;
    rep(i,M) ans = min(ans, dp[N-1][i]);
    return ans;
}

int main(){
    cin >> N;
    rep(i,N) cin >> a[i];
    printf("%.10f\n", solve());
    return 0;
}


