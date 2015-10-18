#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
 
const int inf = 1e9;
 
struct max_flow {
    struct edge { int to, cap, rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;
 
    max_flow() {}
    max_flow(int V) : V(V) { G.assign(V,vector<edge>());}
 
    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, cap, (int) G[from].size()-1});
    }
 
    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }
 
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
    int run(int s, int t, int lim = inf) {
        int ret = 0, f;
        while (bfs(s), level[t] >= 0 and lim) {
            itr.assign(V,0);
            while (lim and (f = dfs(s, t, lim)) > 0) {
                ret += f;
                if(lim != inf) lim -= f;
            }
        }
        return ret;
    }
 
    void cancel(int s, int t) {
        bfs(s);
        itr.assign(V,0);
        if(level[t] >= 0) dfs(s,t,1);
    }
};
 
 
int n, m, q, ex[512][512];
vector<tuple<int,int,int>> qs;
max_flow mf;
 
void solve() {
    int f = mf.run(0,n-1), a, u, v;
    for(auto &q: qs) {
        tie(a,u,v) = q;
        if(a == 1) {
            for(auto &e: mf.G[u]) {
                if(e.to == v) {
                    e.cap = mf.G[v][e.rev].cap = 1;
                    f += mf.run(0,n-1);
                    break;
                }
            }
        }
        else {
            for(auto &e: mf.G[u]) {
                if(e.to == v) {
                    int d = e.cap;
                    e.cap = mf.G[v][e.rev].cap = 0;
                    if(d == 1) break;
                    if(d == 2) {
                        if(mf.run(v,u,1)) break;
                        mf.run(n-1,u,1);
                        mf.run(v,0,1);
                    }
                    else {
                        if(mf.run(u,v,1)) break;
                        mf.run(n-1,v,1);
                        mf.run(u,0,1);
                    }
                    f--;
                    break;
                }
            }
        }
        cout << f << endl;
    }
}
 
void input() {
    cin >> n >> m >> q;
    mf = max_flow(n);
    int a, b, c;
    rep(i,m) {
        cin >> a >> b;
        a--; b--;
        mf.add_edge(a,b,1);
        ex[a][b] = ex[b][a] = 1;
    }
    rep(i,q) {
        cin >> a >> b >> c;
        b--; c--;
        qs.push_back(make_tuple(a,b,c));
        if(!ex[b][c]) {
            ex[b][c] = ex[c][b] = 1;
            mf.add_edge(b,c,0);
        }
    }
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}