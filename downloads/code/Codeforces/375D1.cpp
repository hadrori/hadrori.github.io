#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back

const int M = 100010;
int n, m, idx, depth[M], par[M], ans[M], c[M];

struct query{
    int v, k, id;
    bool operator<(const query &q)const{
        return depth[v] > depth[q.v];
    }
};

vector<int> G[M], ccc[M];
query qs[M];
map<int,int> cnt[M];

void build(int v, int u){
    par[v] = u;
    depth[v] = depth[u]+1;
    for(int &w: G[v])
        if(w != u) build(w,v);
}

// size of v >= size of u
void merge(int v, int u){
    for(auto &p: cnt[u]){
        int &cvf = cnt[v][p.first];
        repi(i,cvf+1,cvf+p.second+1){
            if((int)ccc[v].size() == i) ccc[v].pb(1);
            else ccc[v][i]++;
        }
        cvf += p.second;
    }
    cnt[u].clear();
    ccc[u].clear();
}

void dfs(int v){
    if(cnt[v].size()) return;
    int id = -1, w = 0;
    for(int &u: G[v])
        if(u != par[v]){
            dfs(u);
            if((int)cnt[u].size() > w){
                w = cnt[u].size();
                id = u;
            }
        }
    if(id < 0){
        cnt[v][c[v]] = 1;
        ccc[v] = {0,1};
        return;
    }
    swap(cnt[v], cnt[id]);
    swap(ccc[v], ccc[id]);
    for(int &u: G[v]){
        if(u != par[v] and u != id)
            merge(v, u);
    }
    int &cv = cnt[v][c[v]];
    if((int)ccc[v].size() == cv+1) ccc[v].pb(1);
    else ccc[v][cv+1]++;
    cv++;
}

void solve(){
    depth[0] = -1;
    build(0,0);
    sort(qs, qs+m);
    rep(i,m){
        query &q = qs[i];
        dfs(q.v);
        if(q.k >= (int)ccc[q.v].size()) continue;
        ans[q.id] = ccc[q.v][q.k];
    }
    rep(i,m) printf("%d\n", ans[i]);
}

void input(){
    scanf("%d%d", &n, &m);
    rep(i,n) scanf("%d", c+i);
    rep(i,n-1){
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        G[v].pb(u);
        G[u].pb(v);
    }
    rep(i,m){
        int v, k;
        scanf("%d%d", &v, &k);
        qs[i] = (query){v-1,k,i};
    }
}


int main(){
    input();
    solve();
    return 0;
}
