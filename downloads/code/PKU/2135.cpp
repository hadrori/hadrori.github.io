#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;
const int inf = 1e9;
struct edge{ int to, cap, cost, rev;};
int N, M;

int V;
vector<edge> G[1024];
int h[1024];
int dist[1024];
int prevv[1024], preve[1024];

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, int(G[to].size())});
    G[to].push_back((edge){from, 0, -cost, int(G[from].size() - 1)});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h, h + V, 0);
    while(f > 0){
        priority_queue<pii, vector<pii>, greater<pii> > que;
        fill(dist, dist + V, inf);
        dist[s] = 0;
        que.push(pii(0, s));
        while(!que.empty()){
            pii p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i = 0; i < G[v].size(); i++){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(pii(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == inf) return -1;
        for(int v = 0; v < V; v++) h[v] += dist[v];
        int d = f;
        for(int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * h[t];
        for(int v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main(){
    scanf("%d%d", &N, &M);
    V = N;
    for(int i = 0; i < M; i++){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        add_edge(a, b, 1, c);
        add_edge(b, a, 1, c);
    }
    printf("%d\n", min_cost_flow(0, N-1, 2));
    return 0;
}
