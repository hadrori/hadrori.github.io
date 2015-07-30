#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;
struct edge { int to, cap, cost, rev;};
const int V = 366;
typedef pair<int,int> pii;
vector<edge> G[V];
int h[V], dist[V];
int prevv[V], preve[V];
int N;

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, -cost, int(G[to].size())});
    G[to].push_back((edge){from, 0, cost, int(G[from].size() - 1)});
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
            rep(i,G[v].size()){
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
        rep(v,V) h[v] += dist[v];
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

bool input(){
    cin >> N;
    if(!N) return 0;
    rep(i,V) G[i].clear();
    rep(i,V-1) add_edge(i,i+1,2,0);
    rep(i,N){
        int s, t, c;
        cin >> s >> t >> c;
        add_edge(s-1,t,1,c);
    }
    return 1;
}
signed main(){
    while(input()) cout << -min_cost_flow(0,365,2) << endl;
    return 0;
}


