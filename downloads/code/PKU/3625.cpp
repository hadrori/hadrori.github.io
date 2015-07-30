#include <cmath>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

#define int long long

typedef pair<int,int> pii;

struct edge{
    int a, b, dist;
    edge(int a, int b, int dist):a(a),b(b),dist(dist){}
    bool operator<(const edge &e)const{ return dist > e.dist;}
};

int N, M;
pii farm[1024];

int par[1024], rnk[1024];
void init(){ for(int i = 0; i < N; i++) {par[i] = i; rnk[i] = 1;}}

inline int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]) par[x] = y;
    else{
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[y]++;
    }
}

inline bool same(int x, int y){ return find(x) == find(y);}

inline int sq(int x){ return x * x;}

signed main(){
    scanf("%lld%lld", &N, &M);
    for(int i = 0; i < N; i++){
        int x, y; scanf("%lld%lld", &x, &y);
        farm[i] = pii(x, y);
    }
    init();
    for(int i = 0; i < M; i++){
        int a, b; scanf("%lld%lld", &a, &b);
        a--; b--;
        unite(a, b);
    }
    priority_queue<edge> q;
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            if(!same(i, j)) q.push(edge(i, j, sq(farm[i].first-farm[j].first)+sq(farm[i].second-farm[j].second)));

    double ans = 0.0;
    while(!q.empty()){
        edge e = q.top(); q.pop();
        if(same(e.a, e.b)) continue;
        ans += sqrt(1.*e.dist);
        unite(e.a, e.b);
    }
    printf("%.2f\n", ans);
    return 0;
}
