#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)

int q, n;
int par[1<<20][32], dep[1<<20];

void add(int v){
    par[n][0] = par[n+1][0] = v;
    dep[n] = dep[n+1] = dep[v]+1;
    rep(i,20) par[n][i+1] = par[n+1][i+1] = par[par[n][i]][i];
}

int lca(int u, int v){
    if(dep[u] > dep[v]) swap(u,v);
    int dif = dep[v] - dep[u];
    rep(i,21) if(dif&(1<<i)) v = par[v][i];
    if(u == v) return u;
    for(int i = 20; i >= 0; i--)
        if(par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

int dist(int u, int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}

void solve(){
    int u = 2, v = 3, d = 2, x;
    dep[2] = dep[3] = dep[4] = 1;
    par[2][0] = par[3][0] = par[4][0] = 1;
    n = 5;
    while(q--){
        scanf("%d", &x);
        add(x);
        int du = dist(n,u), dv = dist(n,v);
        if(du > d) v = n, d = du;
        else if(dv > d) u = n, d = dv;
        n += 2;
        printf("%d\n", d);
    }
}

int main(){
    scanf("%d", &q);
    solve();
    return 0;
}
