#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const int inf = 1e9;
const double eps = 1e-9;
struct tr{ int x, y, v;};
struct edge{ int from, to; double d;};
int N, M;
tr troop[128];
pair<int,int> base[128];

const int MAX_V = 256;
int  V;
vector<int> G[MAX_V];
vector<edge> E;
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v] = 1;
    rep(i,G[v].size()){
        int u = G[v][i], w = match[u];
        if(w < 0 || !used[w] && dfs(w)){
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}

int bi_matching(){
    int res = 0;
    memset(match, -1, sizeof(match));
    rep(v,V) if(match[v] < 0){
        memset(used, 0, sizeof(used));
        if(dfs(v)) res++;
    }
    return res;
}


bool can(double lim){
    rep(i,N+M) G[i].clear();
    rep(i,E.size()) if(E[i].d < lim+eps)
        add_edge(E[i].from,E[i].to);
    return bi_matching() == M;
}

inline double sq(double x){ return x*x;}
inline double dist(int i, int j){ return sqrt(sq(troop[i].x-base[j].first)+sq(troop[i].y-base[j].second));}

double solve(){
    V = N+M;
    E.clear();
    rep(i,N) rep(j,M) E.pb((edge){i,j+N,dist(i,j)/troop[i].v});
    double lb = 0.0, ub = inf;
    rep(i,100){
        double mid = (lb+ub)/2.;
        if(can(mid)) ub = mid;
        else lb = mid;
    }
    return ub;
}

bool input(){
    cin >> N >> M;
    if(!N or !M) return 0;
    rep(i,N) cin >> troop[i].x >> troop[i].y >> troop[i].v;
    rep(i,M) cin >> base[i].first >> base[i].second;
    return 1;
}
signed main(){
    while(input()){ printf("%.10f\n", solve());}
    return 0;
}


