#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define int long long
using namespace std;

struct edge{
    int to, cap, rev, dis;
    edge(){}
    edge(int to, int cap, int rev, int dis):to(to),cap(cap),rev(rev),dis(dis){}
};

const int inf = 1e14;
int F, P, sum;
vector<edge> G[512];
vector<edge> tG[512];
int iter[512], level[512];
int cow[256], shelter[256];
int dist[256][256];

void add_edge(int from, int to, int cap, int dis){
    G[from].push_back(edge(to, cap, G[to].size(), dis));
    G[to].push_back(edge(from, 0, G[from].size()-1, dis));
}

void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 and level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 and level[e.to] > level[v]){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

void init(int s, int t, int m){
    for(int i = 0; i <= t; i++)
        for(int j = 0; j < G[i].size(); j++){
            edge &e = G[i][j];
            if(i == s) e.cap = cow[e.to];
            else if(i == t) e.cap = 0;
            else if(i < F) {
                if(e.to == s or e.dis > m) e.cap = 0;
                else e.cap = inf;
            }
            else {
                if(e.to < F) e.cap = 0;
                else e.cap = shelter[i-F];
            }
        }
}

int dinic(int s, int t, int m){
    init(s, t, m);
    int flow = 0, f;
    while(1){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        while((f = dfs(s, t, inf)) > 0) flow += f;
    }
}

signed main(){
    scanf("%lld%lld", &F, &P);
    int s = 2*F, t = 2*F+1;
    memset(dist, -1, sizeof(dist));
    for(int i = 0; i < F; i++){
        scanf("%lld%lld", cow+i, shelter+i);
        add_edge(s, i, cow[i], 0);
        add_edge(F+i, t, shelter[i], 0);
        dist[i][i] = 0;
        sum += cow[i];
    }
    for(int i = 0; i < P; i++){
        int a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
        a--; b--;
        if(dist[a][b] < 0 or dist[a][b] > c)
            dist[a][b] = dist[b][a] = c;
    }
    for(int k = 0; k < F; k++)
        for(int i = 0; i < F; i++){
            if(dist[i][k] < 0) continue;
            for(int j = 0; j < F; j++){
                if(dist[k][j] < 0) continue;
                if(dist[i][j] < 0 or dist[i][j] > dist[i][k]+dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    for(int i = 0; i < F; i++)
        for(int j = 0; j < F; j++)
            if(dist[i][j] >= 0) add_edge(i, F+j, inf, dist[i][j]);
    int lb = 0, ub = inf, mid;
    while(ub - lb > 1){
        mid = (lb + ub) / 2;
        if(dinic(s, t, mid) == sum) ub = mid;
        else lb = mid;
    }
    if(ub == inf) ub = -1;
    printf("%lld\n", ub);
    return 0;
}
