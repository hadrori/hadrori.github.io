#include <cstdio>
#include <vector>

using namespace std;
struct edge{int to, cst;};
vector<edge> G[40010];

const int inf = 1e9;
int N, M, K, bit_V, S;
int bit[80010], id[40010];
int vs[80010], depth[80010], st[(1<<18)+1];

void add(int i, int x){
    while(i <= bit_V){
        bit[i] += x;
        i += i&-i;
    }
}
int sum(int i){
    int ret = 0;
    while(i > 0){
        ret += bit[i];
        i -= i&-i;
    }
    return ret;
}

void dfs(int v, int p, int d, int &k){
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for(int i = 0; i < G[v].size(); i++){
        if(G[v][i].to != p){
            add(k,G[v][i].cst);
            dfs(G[v][i].to, v, d+1, k);
            vs[k] = v;
            depth[k++] = d;
            add(k,-G[v][i].cst);
        }
    }
}

inline int min_id(int a, int b){
    if(depth[a] < depth[b]) return a;
    return b;
}

int query(int a, int b, int k, int l, int r){
    if(r <= a or b <= l) return bit_V+1;
    if(a <= l and r <= b) return st[k];
    int m = (l + r) / 2;
    int vl = query(a, b, k*2+1, l, m);
    int vr = query(a, b, k*2+2, m, r);
    return min_id(vl, vr);
}

void rmq_init(){
    S = 1;
    while(S < bit_V) S <<= 1;
    for(int i = 0; i < 2*S-1; i++) st[i] = bit_V+1;
    depth[bit_V+1] = inf;
    for(int i = 0; i <= bit_V; i++){
        int k = i + S - 1;
        st[k] = i;
        while(k > 0){
            k = (k-1) / 2;
            st[k] = min_id(st[k*2+1], st[k*2+2]);
        }
        /*
        int k = id[i] + S - 1;
        st[k] = id[i];
        while(k > 0){
            k = (k-1) / 2;
            st[k] = min_id(st[k*2+1], st[k*2+2]);
        }
        */
    }
}

void init(){
    bit_V = (N-1)*2;
    int k = 0;
    dfs(0, -1, 0, k);
    rmq_init();
}

int lca(int u, int v){
    return vs[query(min(id[u],id[v]), max(id[u], id[v])+1, 0, 0, S)];
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b, c; char d;
        scanf("%d %d %d %c", &a, &b, &c, &d);
        a--; b--;
        G[a].push_back(edge{b,c});
        G[b].push_back(edge{a,c});
    }
    init();
    scanf("%d", &K);
    while(K--){
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        int p = lca(u, v);
        printf("%d\n", sum(id[v])+sum(id[u])-2*sum(id[p]));
    }
    return 0;
}
