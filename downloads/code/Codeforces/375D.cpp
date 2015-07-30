#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int M = 100010, B = 400;
int n, m, idx, par[M],
    ans[M], l[M], r[M], id[M], // [l, r)
    c[M], cc[M], ccc[M]; // color, color count, color count count
struct query{
    int v, k, id;
    bool operator<(const query &q)const{
        if(l[v]/B != l[q.v]/B) return l[v] < l[q.v];
        return r[v] < r[q.v];
    }
};

vector<int> G[M];
query qs[M];

void build_lr(int v, int u){
    id[idx] = v;
    par[v] = u;
    l[v] = idx++;
    for(int &w: G[v])
        if(w != u) build_lr(w,v);
    r[v] = idx;
}


void solve(){
    build_lr(0,0);
    sort(qs, qs+m);
    int ls = 0, rs = 0;
    rep(i,m){
        query &q = qs[i];
        while(ls < l[q.v]) --ccc[cc[c[id[ls++]]]--];
        while(ls > l[q.v]) ++ccc[++cc[c[id[--ls]]]];
        while(rs < r[q.v]) ++ccc[++cc[c[id[rs++]]]];
        while(rs > r[q.v]) --ccc[cc[c[id[--rs]]]--];
        ans[q.id] = ccc[q.k];
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
