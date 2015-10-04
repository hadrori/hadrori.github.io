#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

inline void chmin(int &x, int y) { x = min(x,y); }
const int inf = 1e9;
int n, m, d[1024], c[1024], dp[1024][1024];

int solve() {
    rep(i,n+1) rep(j,m+1) dp[i][j] = inf;
    dp[0][0] = 0;
    rep(i,n) rep(j,m) {
        chmin(dp[i][j+1], dp[i][j]);
        chmin(dp[i+1][j+1], dp[i][j]+d[i]*c[j]);
    }
    return *min_element(dp[n], dp[n]+m+1);
}

void input() {
    cin >> n >> m;
    rep(i,n) cin >> d[i];
    rep(i,m) cin >> c[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}