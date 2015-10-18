#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int mod = 1e9+7;
inline void add(int &x, int y) { x=(x+y)%mod; }
inline int mul(int x, int y) { return 1LL*x*y%mod; }

int n, f[32], dp[32][310], c[310][310], sum[32];

int solve()
{
    rep(i,300) {
        c[i][0] = 1;
        repi(j,1,i+1) c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
    }

    sort(f,f+26);
    n = 26-(upper_bound(f,f+26,0)-f);
    reverse(f,f+26);

    rep(i,n) sum[i+1] = sum[i]+f[i];
    dp[0][0] = 1;
    rep(i,n) rep(j,sum[i]+1) repi(k,1,f[i]+1) rep(l,min(j,k)+1)
        add(dp[i+1][j-l+f[i]-k], mul(dp[i][j], mul(c[f[i]-1][k-1], mul(c[j][l], c[sum[i]+1-j][k-l]))));
    return dp[n][0];
}

void input()
{
    rep(i,26) cin >> f[i];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
