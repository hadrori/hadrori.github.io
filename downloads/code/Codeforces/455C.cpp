#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const int MAX = 300010;

struct union_find{
    int rnk[MAX], par[MAX], diam[MAX];
    union_find(){}
    union_find(int n){
        for(int i = 0; i < n; i++){
            rnk[i] = 1;
            par[i] = i;
            diam[i] = 0;
        }
    }
    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return;
        if(diam[x] < diam[y]) swap(x,y);
        diam[x] = diam[y] = max(diam[x], (diam[x]+1)/2+(diam[y]+1)/2+1);
        if(rnk[x] > rnk[y]) par[y] = x;
        else{
            par[x] = y;
            if(rnk[x] == rnk[y]) rnk[y]++;
        }
    }
};

int n, m, q, a, b, t;
vector<int> G[300010];
int done[300010];
union_find uf;

void dfs(int v, int u, int l, int &d, int &w){
    done[v] = 1;
    uf.unite(u,v);
    if(l > d) {
        d = l;
        w = v;
    }
    for(int &x: G[v]) if(x != u) dfs(x,v,l+1,d,w);
}

void build_tree(){
    uf = union_find(n);
    rep(i,n) if(!done[i]){
        int w = i, d = 0;
        dfs(i,i,0,d,w);
        d = 0;
        dfs(w,w,0,d,w);
        uf.diam[uf.find(i)] = d;
    }
}

void solve(){
    build_tree();
    while(q--){
        scanf("%d", &t);
        --t;
        if(t) {
            scanf("%d%d", &a, &b);
            uf.unite(a-1,b-1);
        }
        else {
            scanf("%d", &a);
            printf("%d\n", uf.diam[uf.find(a-1)]);
        }
    }
}

void input(){
    scanf("%d%d%d", &n, &m, &q);
    rep(i,m){
        scanf("%d%d", &a, &b);
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }
}

int main(){
    input();
    solve();
    return 0;
}
