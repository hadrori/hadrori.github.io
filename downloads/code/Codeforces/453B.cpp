#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,a) repi(i,0,a)
const int inf = 1e9, mx = 59;

int n, a[128], b[128];
const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53}, mp = 16;
int fac[64], dp[128][1<<mp], num[128][1<<mp], pre[128][1<<mp];

void gen(){
    repi(i,1,mx) rep(j,mp)
        if(__gcd(i,primes[j])>1) fac[i] |= 1<<j;
}

void solve(){
    gen();
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    rep(i,n) rep(j,1<<mp) repi(k,1,mx){
        if((j&fac[k]) or dp[i][j]<0) continue;
        int ni = i+1, nj = j|fac[k];
        if(dp[ni][nj]<0 or dp[ni][nj] > dp[i][j]+abs(a[i]-k)){
            dp[ni][nj] = dp[i][j]+abs(a[i]-k);
            pre[ni][nj] = j;
            num[ni][nj] = k;
        }
    }

    int sum = inf, nj = 0;
    rep(j,1<<mp) if(dp[n][j] >= 0 and sum > dp[n][j]) {
        sum = dp[n][j];
        nj = j;
    }

    for(int i=n; i>0; --i){
        b[i-1] = num[i][nj];
        nj = pre[i][nj];
    }
    rep(i,n) cout << b[i] << " "; cout << endl;
}

void input(){
    cin >> n;
    rep(i,n) cin >> a[i];
}

signed main(){
    cin.sync_with_stdio(0);
    input();
    solve();
    return 0;
}
