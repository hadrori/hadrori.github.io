#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int inf = 1e9;
int n, f[1024][1024], dp[1024][1024], sum[1024][1024];

int solve() {
    rep(i,n) rep(j,n) sum[i][j+1] = sum[i][j]+f[i][j];
    repi(i,1,n) {
        int m = -inf;
        rep(j,i+1) {
            m = max(m, dp[i-1][j]);
            dp[i][j] = m+sum[i][i]-sum[i][j];
        }
    }
    int ans = -inf;
    rep(i,n) ans = max(ans, dp[n-1][i]);
    return ans*2;
}

void input() {
    scanf("%d", &n);
    rep(i,n) rep(j,n) scanf("%d", f[i]+j);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
