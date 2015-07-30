#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

template<class T> class bit
{
public:
        vector<T> dat;
        int N;
        
        bit(){}
        bit(int N) : N(N){
                dat.assign(N,0);
        }
        // sum [0,i)
        T sum(int i){
                T ret = 0;
                for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
                return ret;
        }
        // sum [i,j)
        T sum(int i, int j){ return sum(j) - sum(i);}
        // add x to i
        void add(int i, T x){ for(; i < N; i|=i+1) dat[i] += x;}
};


int n, m;
vector<pii> G[100010], es;

int dep[100010], par[100010][32], in[100010], out[100010], dist[100010][2];
bit<int> up, down;

void dfs(int v, int u, int d, int &idx)
{
        if(v) {
                dep[v] = d;
                par[v][0] = u;
                int k = 0;
                while(par[par[v][k]][k] >= 0) {
                        par[v][k+1] = par[par[v][k]][k];
                        k++;
                }
                up.add(idx,1);
                down.add(idx,1);
        }
        in[v] = idx++;
        for(auto &e: G[v])
                if(e.first != u) dfs(e.first, v, d+1, idx);

        if(v) {
                up.add(idx,-1);
                down.add(idx,-1);
        }
        out[v] = idx++;
}

void build_tree()
{
        memset(par,-1,sizeof(par));
        up = bit<int>(2*n);
        down = bit<int>(2*n);
        int idx = 0;
        dfs(0,-1,0, idx);
}

int lca(int u, int v)
{
        if(dep[u] > dep[v]) swap(u,v);
        int dif = dep[v] - dep[u];
        for (int i = 0; i < 18; i++)
                if(dif&(1<<i)) v = par[v][i];
        if(u == v) return u;
        for (int i = 17; i >= 0; i--)
                if(par[u][i] != par[v][i]) {
                        u = par[u][i];
                        v = par[v][i];
                }
        return par[u][0];
}

void solve()
{
        build_tree();
        char c;
        int u, v, w, r, s, t;
        while(m--) {
                cin >> c;
                if(c == 'I') {
                        cin >> r >> s >> t;
                        r--;
                        u = es[r].first;
                        v = es[r].second;
                        if(dep[v] > dep[u]) {
                                swap(u,v);
                                swap(s,t);
                        }
                        up.add(in[u], -dist[r][0]+s);
                        up.add(out[u], dist[r][0]-s);
                        down.add(in[u], -dist[r][1]+t);
                        down.add(out[u], dist[r][1]-t);
                        dist[r][0] = s;
                        dist[r][1] = t;
                }
                else {
                        cin >> u >> v;
                        u--; v--;
                        w = lca(u,v);
                        cout << up.sum(in[w]+1,in[u]+1)+down.sum(in[w]+1,in[v]+1) << endl;
                }
        }
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < n-1; i++) {
                int p, q; cin >> p >> q;
                dist[i][0] = dist[i][1] = 1;
                p--; q--;
                G[p].push_back(pii(q,i));
                G[q].push_back(pii(p,i));
                es.push_back(pii(p,q));
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
