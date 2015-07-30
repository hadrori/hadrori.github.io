#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e9;
struct edge{int to, cap, rev;};
vector<edge> E[512];

int N, M;
int level[512], iter[512];

void add_edge(int from, int to, int cap){
    E[from].push_back(edge{to, cap, int(E[to].size())});
    E[to].push_back(edge{from, 0, int(E[from].size()-1)});
}

void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i = 0; i < E[v].size(); i++){
            edge &e = E[v][i];
            if(e.cap > 0 and level[e.to] < 0) {
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i = iter[v]; i < E[v].size(); i++){
        edge &e = E[v][i];
        if(e.cap > 0 and level[e.to] > level[v]){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                E[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int dinic(int s, int t){
    int flow = 0;
    while(1){
        bfs(s);
        if(level[t]< 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, inf)) > 0) flow += f;
    }
}


void init(){
    for(int i = 0; i < 512; i++)
        E[i].clear();
}
int main(){
    while(~scanf("%d%d", &N, &M)){
        init();
        int s = N+M, t = N+M+1;
        for(int i = 0; i < N; i++){
            add_edge(s, i, 1);
            int m; scanf("%d", &m);
            for(int j = 0; j < m; j++){
                int n; scanf("%d", &n);
                add_edge(i, N+n-1, 1);
            }
        }
        for(int i = 0; i < M; i++)
            add_edge(N+i,t,1);
        printf("%d\n", dinic(s,t));
    }
}
