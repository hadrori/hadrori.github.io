#include <bits/stdc++.h>
using namespace std;

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


int n, m, done[1<<17], id[1<<17], in[1<<17], out[1<<17];
vector<int> G[1<<17], rG[1<<17], vs;
vector<vector<int>> scc;
bit<int> b;

void scc_dfs(int v)
{
        done[v] = 1;
        for(auto &w: G[v]) if(!done[w]) scc_dfs(w);
        vs.push_back(v);
}

void scc_rdfs(int v, int k)
{
        done[v] = 1;
        id[v] = k;
        scc.back().push_back(v);
        for(auto &w: rG[v]) if(!done[w]) scc_rdfs(w,k);
}

void stronglyCC()
{
        for (int i = 0; i < n; i++)
                if(!done[i]) scc_dfs(i);
        memset(done,0,sizeof(done));
        reverse(begin(vs),end(vs));
        int k = 0;
        for(auto &v: vs) if(!done[v]) {
                        scc.push_back(vector<int>());
                        scc_rdfs(v,k++);
                }
}

void dfs(int v, int &idx)
{
        done[v] = 1;
        in[v] = idx++;
        int cnt = 0;
        for(auto &w: scc[v]) {
                for(auto &x: G[w]) 
                        if(!done[id[x]]) dfs(id[x], idx);
        }
        if(!cnt) vs.push_back(v);
        out[v] = idx;
}

void solve()
{
        stronglyCC();
        m = scc.size();
        vs.clear();

        int idx = 0;
        memset(done,0,sizeof(done));
        for (int i = 0; i < m; i++) {
                if(done[i]) continue;
                int f = 1;
                for(auto &w: scc[i]) {
                        for(auto &x: rG[w])
                                if(id[x] != i) {
                                        f = 0;
                                        break;
                                }
                        if(!f) break;
                }
                if(f) dfs(i,idx);
        }

        memset(done,0,sizeof(done));
        b = bit<int>(2*m);
        for (int i = 0; i < n; i++) {
                cout << b.sum(in[id[i]],out[id[i]]) << endl;
                b.add(in[id[i]], 1);
        }
}

void input()
{
        cin >> n;
        int p;
        for (int i = 0; i < n; i++) {
                cin >> p; p--;
                G[p].push_back(i);
                rG[i].push_back(p);
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
