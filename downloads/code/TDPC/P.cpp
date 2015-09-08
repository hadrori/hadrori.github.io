#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int mod = 1e9+7;
inline void add(int &x, int y) {x+=y;if(x>=mod)x-=mod;}
inline int mul(int x, int y) {return 1LL*x*y%mod;}

int N, K, dp[1024][64][4], dp2[1024][64][4];
vector<int> g[1024];

void dfs(int v, int u) {
    vector<int> cs;
    for(auto &e: g[v]) if(e != u) {
            cs.push_back(e);
            dfs(e,v);
        }
    memset(dp2,0,sizeof(dp2));
    dp2[0][0][0] = 1;
    rep(i,cs.size()) rep(j,K+1) rep(k,3) rep(l,K+1) rep(m,3) {
        int val = mul(dp2[i][j][k], dp[cs[i]][l][m]);
        if(!val or j+l > K+1) continue;
        add(dp2[i+1][j+l][k], val);
        if(k == 0) {
            if(m == 0) add(dp2[i+1][j+l+1][1], val);
            if(m == 1) add(dp2[i+1][j+l][1], val);
        }
        if(k == 1) {
            if(m == 0) add(dp2[i+1][j+l][2], val);
            if(m == 1) add(dp2[i+1][j+l-1][2], val);
        }
    }
    memcpy(dp[v], dp2[cs.size()], sizeof(dp[v]));
}

int solve() {
    dfs(0,-1);
    return (1LL*dp[0][K][0]+dp[0][K][1]+dp[0][K][2])%mod;
}

void input() {
    cin >> N >> K;
    int a, b;
    rep(i,N-1) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
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