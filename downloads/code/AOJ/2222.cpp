#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define all(u) begin(u),end(u)
const int mod = 1e9+7;

vector<int> G[1024], rG[1024], vs;
vector<vector<int>> s;
int S[1024], vis[1024], dp[1024];
int N, M;

void dfs(int v){
    vis[v] = 1;
    rep(i,G[v].size())
        if(!vis[G[v][i]]) dfs(G[v][i]);
    vs.pb(v);
}

void rdfs(int v, int k){
    vis[v] = 1;
    S[v] = k; s[k].pb(v);
    rep(i,rG[v].size())
        if(!vis[rG[v][i]]) rdfs(rG[v][i],k);
}

void scc(){
    rep(i,N)if(!vis[i]) dfs(i);
    memset(vis,0,sizeof(vis)); reverse(all(vs));
    s.clear();
    rep(i,N) if(!vis[vs[i]]){
        s.pb(vector<int>());
        rdfs(vs[i],s.size()-1);
    }
    N = s.size();
}

inline void f(int &a, int b){a=(a*b)%mod;}

int solve(){
    scc();
    rep(i,N) dp[i] = 1;
    int cnt, ans = 1;
    rep(i,N){
        bool done[1024] = {};
        cnt = 0; done[i] = 1;
        rep(j,s[i].size())rep(k,G[s[i][j]].size()){
            int to = S[G[s[i][j]][k]];
            if(!done[to]) {
                done[to] = 1; cnt++;
                f(dp[to],dp[i]+1);
            }
        }
        if(cnt==0) f(ans,dp[i]+1);
    }
    return ans;
}

void input(){
    cin >> N >> M;
    rep(i,M){
        int s, d; cin >> s >> d;
        s--; d--;
        G[s].pb(d);
        rG[d].pb(s);
    }
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
