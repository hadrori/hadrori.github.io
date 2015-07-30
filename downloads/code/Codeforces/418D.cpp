#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
typedef pair<int,int> pii;
const int M1 = 100010, M2 = 32;

int N, M, E;
vector<int> G[M1];
inline void add_edge(int u, int v){ G[u].pb(v); G[v].pb(u);}
inline void chmax(int &a, int b){a=max(a,b);}
int par[M1][M2], depth[M1], up[M1][M2], down[M1][M2];
pii max3[M1][3];

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int dif = depth[u]-depth[v];
    rep(i,E) if((dif>>i)&1) u = par[u][i];
    if(u==v) return u;
    for(int k = E-1; k >= 0; k--)
        if(par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    return par[u][0];
}

void build_max3(int v, int u, int d){
    depth[v] = d;
    for(int &w: G[v]) if(w != u){
        build_max3(w,v,d+1);
        if(max3[w][0].first+1 > max3[v][2].first){
            max3[v][2].first = max3[w][0].first+1;
            max3[v][2].second = w;
            sort(max3[v], max3[v]+3);
            reverse(max3[v], max3[v]+3);
        }
    }
}

void build_updown(int v, int u){
    par[v][0] = u;
    rep(i,3){
        if(max3[u][i].second == v) continue;
        up[v][0] = max3[u][i].first+1;
        down[v][0] = max3[u][i].first+1;
        break;
    }
    rep(i,E) if(par[v][i] != -1){
        par[v][i+1] = par[par[v][i]][i];
        if(par[v][i+1] < 0) break;
        up[v][i+1] = max(up[v][i], up[par[v][i]][i]+(1<<i));
        down[v][i+1] = max(down[par[v][i]][i], down[v][i]+(1<<i));
    }
    for(int &w: G[v]) if(w != u) build_updown(w,v);
}

void build(){
    E = 0;
    while((1<<E) < N) E++;
    memset(par,-1,sizeof(par));
    build_max3(0,-1,0);
    for(int &w: G[0]) build_updown(w,0);
}

int get_center(int u, int d){
    d = (d-1)/2;
    for(int i = E; i >= 0; i--)
        if(d&(1<<i)) u = par[u][i];
    return u;
}

int get_umax(int v, int d){
    int cnt = 0, ret = 0;
    if(d<0) return -1e9;
    rep(i,E) if(d&(1<<i)){
        chmax(ret, up[v][i]+cnt);
        cnt |= 1<<i;
        v = par[v][i];
    }
    return ret;
}

int get_dmax(int v, int d){
    int ret = 0;
    if(d<0) return -1e9;
    rep(i,E) if(d&(1<<i)){
        d ^= 1<<i;
        chmax(ret, down[v][i]+d);
        v = par[v][i];
    }
    return ret;
}

int query(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int w = lca(u,v), ans = max3[u][0].first;
    int d = depth[u]+depth[v]-2*depth[w];
    int vwd = depth[v]-depth[w], c = get_center(u,d);
    chmax(ans, get_umax(v, vwd-1));
    chmax(ans, get_umax(u, (d-1)/2));
    chmax(ans, get_umax(w, depth[w])+vwd);
    chmax(ans, get_dmax(c, depth[c]-depth[w]-1)+vwd);
    if(w != v) chmax(ans, max3[v][0].first);
    rep(i,3){
        int a = lca(max3[w][i].second, u), b = lca(max3[w][i].second, v);
        if(a == max3[w][i].second or b == max3[w][i].second) continue;
        chmax(ans, max3[w][i].first+vwd);
        break;
    }
    return ans;
}

void solve(){
    build();
    while(M--){
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", query(u-1,v-1));
    }
}

void input(){
    scanf("%d", &N);
    rep(i,N-1){
        int u, v; scanf("%d%d", &u, &v);
        add_edge(u-1,v-1);
    }
    scanf("%d", &M);
}

int main(){
    input();
    solve();
    return 0;
}
