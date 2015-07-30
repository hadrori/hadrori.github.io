#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back

const int MAX = 512;
typedef pair<int,int> pii;
vector<pii> G[MAX];
bitset<MAX> ans, bad[MAX][MAX];
int w[MAX], dp[MAX][MAX], acnt, N, K;

void rec(int v, int u){
    w[v] = 1;
    dp[v][0] = dp[v][1] = 0;
    rep(k,G[v].size()){
        int &x = G[v][k].first, &id = G[v][k].second;
        if(x == u) continue;
        bad[x][0][id] = 1;
        rec(x, v);
        int ndp[MAX] = {};
        bitset<MAX> nbad[MAX];
        nbad[0] = bad[v][0];
        repi(i,1,w[v]+1) ndp[i] = dp[v][i]+1, nbad[i] = bad[v][i], nbad[i][id] = 1;
        repi(i,1,w[x]+1) repi(j,1,w[v]+1)
            if(!ndp[i+j] or ndp[i+j] > dp[v][j]+dp[x][i]){
                ndp[i+j] = dp[v][j]+dp[x][i];
                nbad[i+j] = bad[v][j] | bad[x][i]; 
            }
        w[v] += w[x];
        rep(i,w[v]+1) dp[v][i] = ndp[i], bad[v][i] = nbad[i];
    }
    if(w[v] >= K and acnt > dp[v][K] + (v!=0)) {
        ans = bad[v][K] | bad[v][0];
        acnt = dp[v][K] + (v!=0);
    }
}

void solve(){
    memset(dp,-1,sizeof(dp));
    acnt = N+1;
    rec(0,-1);
    printf("%d\n", acnt);
    rep(i,N) if(ans[i]) printf("%d ", i);
    puts("");
}

void input(){
    scanf("%d%d", &N, &K);
    rep(i,N-1){
        int x, y; scanf("%d%d", &x, &y);
        x--; y--;
        G[x].pb(pii(y,i+1));
        G[y].pb(pii(x,i+1));
    }
}

int main(){
    input();
    solve();
    return 0;
}
