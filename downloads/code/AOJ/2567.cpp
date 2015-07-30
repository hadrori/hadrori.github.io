#include <iostream>

#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define INF 1e9

using namespace std;

int n, m, l, s, t;
int wf[310][310], jiro[310], id[20], dp[1<<17][20];

bool input(){
    cin >> n >> m >> l >> s >> t;
    s--;
    if(!n) return 0;
    rep(i,n) rep(j,n) wf[i][j] = INF;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        wf[a][b] = c;
        wf[b][a] = c;
    }
    rep(i,l) {
        int j, e;
        cin >> j >> e;
        jiro[i] = e;
        id[i] = j-1;
    }
    jiro[l] = 0;
    id[l] = s;
    return 1;
}

int solve(){
    rep(k,n) rep(i,n) rep(j,n)
        wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);

    rep(S,1<<(l+1)) rep(j,l+1) dp[S][j] = INF;
    dp[0][l] = 0;
    rep(i,l) dp[1<<i][i] = wf[s][id[i]] + jiro[i];

    repi(S,1,1<<(l+1)) rep(v,l+1) if(!((S >> v) & 1))
        rep(u,l+1) if((S >> u) & 1)
            dp[S | (1 << v)][v] = min(dp[S|(1<<v)][v], dp[S][u] + wf[id[u]][id[v]] + jiro[v]);

    int ans = 0;
    rep(S, 1<<(l+1)) if(dp[S][l] <= t)
        ans = max(ans, (int)__builtin_popcount(S) - 1);

    return ans;
}

signed main(){
    while(input()){ cout << solve() << endl;}
    return 0;
}
