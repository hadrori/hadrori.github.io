#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int N, W, C, w[128], v[128], c[128], dp[10010][60], dp2[10010][60];

int solve() {
    rep(i,50) {
        vector<int> ws, vs;
        rep(j,N) if(c[j] == i) {
            ws.push_back(w[j]);
            vs.push_back(v[j]);
        }
        memcpy(dp, dp2, sizeof(dp));
        rep(j,ws.size()) for(int k = W; k >= ws[j]; k--) rep(l,C+1) dp[k][l] = max(dp[k][l], dp[k-ws[j]][l]+vs[j]);
        rep(j,W+1) rep(k,C) dp2[j][k+1] = max(dp2[j][k+1], dp[j][k]);
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
