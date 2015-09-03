#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

inline void chmax(int &x, int y) { x = max(x, y); }

int n, m, id[310], w[310], done[310], dp[310][310], h[310][310];
vector<int> g[310], rg[310], f[310], scc[310], vs;

void dfs(int v) {
    if(done[v]) return;
    done[v] = 1;
    rep(i,g[v].size()) dfs(g[v][i]);
    vs.push_back(v);
}

void dfs2(int v) {
    if(!done[v]) return;
    done[v] = 0;
    id[v] = m;
    scc[m].push_back(v);
    rep(i,rg[v].size()) dfs2(rg[v][i]);
}

void topo(int v) {
    if(done[v]) return;
    done[v] = 1;
    rep(i,f[v].size()) topo(f[v][i]);
    vs.push_back(v);
}

int solve() {
    rep(i,n) dfs(i);
    m = 1;
    rep(i,n) if(done[vs[n-i-1]]) { dfs2(vs[n-i-1]); m++; }

    rep(i,m) {
        w[i] = scc[i].size();
        rep(j,w[i]) for(int &v: g[scc[i][j]]) f[i].push_back(id[v]);
        sort(begin(f[i]),end(f[i]));
        f[i].erase(unique(begin(f[i]),end(f[i])),end(f[i]));
    }
    rep(i,m-1) f[0].push_back(i+1);
    rep(i,m) rep(j,f[i].size()) h[i][f[i][j]] = 1;
    rep(k,m) rep(i,m) rep(j,m) h[i][j] |= h[i][k]&h[k][j];

    memset(done,0,sizeof(done));
    vs.clear();
    rep(i,m) topo(i);
    reverse(begin(vs),end(vs));

    rep(i,m) rep(j,i) {
        int u = vs[i], v = vs[j];
        chmax(dp[u][v], w[u]+w[v]);
        repi(k,i+1,m) {
            int nu = vs[k];
            if(h[u][nu]) chmax(dp[nu][v], dp[u][v]+w[nu]);
            if(h[v][nu]) chmax(dp[nu][u], dp[u][v]+w[nu]);
        }
    }
    int ans = 0;
    rep(i,m) rep(j,m) ans = max(ans, dp[i][j]);
    return ans;
}

void input() {
    cin >> n;
    int x;
    rep(i,n) rep(j,n) {
        cin >> x;
        if(x) {
            g[i].push_back(j);
            rg[j].push_back(i);
        }
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
