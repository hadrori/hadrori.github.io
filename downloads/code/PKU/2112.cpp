#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct edge{ int to, cap, rev;};

const int inf = 1e9;
int K, C, M;
int dist[256][256], level[256], iter[256];
vector<edge> G[256];

void add_edge(int from, int to, int cap){
    G[from].push_back(edge{to, cap, int(G[to].size())});
    G[to].push_back(edge{from, 0, int(G[from].size()-1)});
}

void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i++)
            if(G[v][i].cap > 0 and level[G[v][i].to] < 0) {
                que.push(G[v][i].to);
                level[G[v][i].to] = level[v] + 1;
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

int dinic(int s, int t){
    int flow = 0, f;
    while(1){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        while((f = dfs(s,t,inf)) > 0) flow += f;
    }
}

#include <iostream>

bool ok(int m){
    for(int i = 0; i < K+C+2; i++)
        G[i].clear();
    int s = K+C, t = K+C+1;
    for(int i = K; i < s; i++)
        add_edge(s, i, 1);
    for(int i = 0; i < K; i++){
        add_edge(i, t, M);
        for(int j = K; j < s; j++)
            if(dist[i][j] <= m)
                add_edge(j, i, 1);
    }
    int d = dinic(s, t);
    return d == C;
}

int main(){
    scanf("%d%d%d", &K, &C, &M);
    for(int i = 0; i < K + C; i++)
        for(int j = 0; j < K + C; j++){
            scanf("%d", &dist[i][j]);
            if(dist[i][j] == 0) dist[i][j] = inf;
        }
    for(int k = 0; k < K+C; k++)
        for(int i = 0; i < K+C; i++)
            for(int j = 0; j < K+C; j++)
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
    int lb = 0, ub = 100000;
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if(ok(mid)) ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;
}
