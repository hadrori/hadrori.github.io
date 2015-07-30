#include <cstdio>
#include <queue>
#include <map>

using namespace std;

struct edge{
    int a, b, c;
    edge(){}
    edge(int a, int b, int c):a(a),b(b),c(c){}
    bool operator<(const edge &e)const{return c < e.c;}
};

int N, M;

int par[1024], rnk[1024];

void init(){
    for(int i = 0; i < N; i++){
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

inline bool same(int x, int y){ return find(x) == find(y);}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]) par[x] = y;
    else{
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x]++;
    }
}


int main(){
    scanf("%d%d", &N, &M);
    init();
    priority_queue<edge> que;
    for(int i = 0; i < M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        que.push(edge(a, b, c));
    }

    int ans = 0;
    while(!que.empty()){
        edge e = que.top(); que.pop();
        if(same(e.a,e.b)) continue;
        unite(e.a,e.b);
        ans += e.c;
    }
    bool ok = 1;
    for(int i = 1; i < N; i++)
        if(!same(0,i)) { ok = 0; break;}
    if(!ok) puts("-1");
    else printf("%d\n", ans);
    return 0;
}
