#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1e9;
struct edge{int to, cap, rev;};
vector<edge> G[512];
int D, F, N;
int iter[512], level[512];

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
        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 and level[e.to] < 0){
                que.push(e.to);
                level[e.to] = level[v] + 1;
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
            if(d > 0) {
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
        while((f = dfs(s, t, inf)) > 0) flow += f;
    }
}

int main(){
    scanf("%d%d%d", &N, &F, &D);
    for(int i = 0; i < N; i++){
        add_edge(F+i, F+N+i, 1);
        int f, d; scanf("%d%d", &f, &d);
        for(int j = 0; j < f; j++){
            int food; scanf("%d", &food);
            add_edge(food-1, F+i, 1);
        }
        for(int j = 0; j < d; j++){
            int drink; scanf("%d", &drink);
            add_edge(F+N+i, F+2*N+drink-1, 1);
        }
    }
    int s = F+2*N+D, t = F+2*N+D+1;
    for(int i = 0; i < F; i++)
        add_edge(s, i, 1);
    for(int i = 0; i < D; i++)
        add_edge(F+2*N+i, t, 1);
    printf("%d\n", dinic(s, t));
    return 0;
}
