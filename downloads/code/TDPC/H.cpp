#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int N, W, C, w[128], v[128], c[128], dp[10010][60], dp2[10010][60];

int solve() {
    rep(i,50) {
        memcpy(dp, dp2, sizeof(dp));
        rep(j,N) if(c[j] == i)
            for(int k = W; k >= w[j]; k--)
                rep(l,C+1) dp[k][l] = max(dp[k][l], dp[k-w[j]][l]+v[j]);
        rep(k,W+1) rep(l,C) dp2[k][l+1] = max(dp2[k][l+1], dp[k][l]);
    }
    int ans = 0;
    rep(i,W+1) rep(j,C+1) ans = max(ans, dp2[i][j]);
    return ans;
}

void input() {
    cin >> N >> W >> C;
    rep(i,N) {
        cin >> w[i] >> v[i] >> c[i];
        c[i]--;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
