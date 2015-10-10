#include <bits/stdc++.h>
using namespace std;
 
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
 
inline void chmax(int &x, int y) { x = max(x, y); }
int c, d, w, x, e[32][32], f[32][32], dp[32][64][8], sume[32], sumf[32];
 
int solve() {
    memset(dp, 0, sizeof(dp));
    rep(i,d) {
        rep(j,c) {
            sume[j+1] = sume[j] + e[i][j];
            sumf[j+1] = sumf[j] + f[i][j];
        }
        rep(j,w+1) rep(k,x+1) {
            chmax(dp[i+1][j][k], dp[i][j][k]);
            rep(l,c) repi(r,l+1,c+1) {
                if(!e[i][r-1]) break;
                int nj = j+sumf[r]-sumf[l], nk = k+(r-l>1);
                if(nj <= w and nk <= x) chmax(dp[i+1][nj][nk], dp[i][j][k]+sume[r]-sume[l]);
            }
        }
    }
    int ans = 0;
    rep(j,w+1) rep(k,x+1) chmax(ans, dp[d][j][k]);
    return ans;
}
 
bool input() {
    cin >> c >> d >> w >> x;
    rep(i,c) rep(j,d) cin >> e[j][i];
    rep(i,c) rep(j,d) cin >> f[j][i];
    return c or d or w or x;
}
 
int main() {
    while(input()) cout << solve() << endl;
    return 0;
}