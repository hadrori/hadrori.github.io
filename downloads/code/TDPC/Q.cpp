#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int mod = 1000000007;
inline void add(int &x, int y) { x=(x+y)%mod; }
int N, L, w[16][256], dp[128][128][256];

int solve() {
    dp[0][0][1] = 1;
    rep(i,L) rep(j,128) rep(k,256) rep(l,2) if(dp[i][j][k]) {
        int f = 0;
        rep(m,8) if(k>>m&1 and w[m+1][(j*2+l)&((1<<(m+1))-1)]) f |= 1;
        add(dp[i+1][j*2&127|l][k*2&255|f], dp[i][j][k]);
    }
    int ans = 0;
    rep(i,128) rep(j,128) add(ans, dp[L][i][j*2+1]);
    return ans;
}

void input() {
    cin >> N >> L;
    string s;
    rep(i,N) {
        cin >> s;
        int x = 0;
        rep(j,s.size()) x |= (s[j]-'0')<<j;
        w[s.size()][x] = 1;
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
