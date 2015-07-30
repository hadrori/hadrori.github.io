#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
const int inf = 1e9;
struct edge{ int to, cap, cost, rev;};
int N, P, T;
vector<edge> G[256];
int iter[256], level[256];

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, int(G[to].size())});
    G[to].push_back((edge){from, cap, cost, int(G[from].size() - 1)});
}

void bfs(int s, int m){
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

int dinic(int s, int t, int m){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < G[i].size(); j++)
            if(G[i][j].cost > m) G[i][j].cap = 0;
            else G[i][j].cap = 1;

    int flow = 0, f;
    while(1){
        bfs(s, m);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        while((f = dfs(s, t, inf)) > 0) flow += f;
    }
}

int main(){
    scanf("%d%d%d", &N, &P, &T);
    for(int i = 0; i < P; i++){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add_edge(a-1, b-1, 1, c);
    }
    int lb = 0, ub = 10000000, mid;
    while(ub - lb > 1){
        mid = (lb + ub) / 2;
        //        printf("%d %d %d\n", lb, ub, dinic(0,N-1,mid));
        if(dinic(0, N-1, mid) >= T) ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;
}
