#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = INT_MAX;
const int N = 200000;
 
// non directional tree
vector<int> G[N];
int val[N]; // number of nodes, value of node(only for init)
int dep[N], par[N], size[N]; // depth, parent, size
int heavy[N], head[N]; // next heavy node, head of chain
int chain[N], id[N]; // belong, index in chain
 
struct HL_Decomposition
{
        int n;
        vector<vector<int>> chains, vals;
         
        void hl_bfs(int rt = 0) // default root is vertex 0
        {
                par[rt] = -1;
                dep[rt] = 0;
                int q[N], l = 0, r = 0;
                q[r++] = rt;
                while(l < r) {
                        const int &v = q[l++];
                        for(auto &w: G[v]) {
                                if(w == par[v]) continue;
                                par[w] = v;
                                dep[w] = dep[v]+1;
                                q[r++] = w;
                        }
                }
                memset(size,0,sizeof(size));
                memset(heavy,-1,sizeof(heavy));
                for (int i = n-1; i > 0 ; i--) {
                        const int &v = q[i], &u = par[v];
                        size[u] += ++size[v];
                        if(heavy[u] == -1 or size[v] > size[heavy[u]]) heavy[u] = v;
                }
                chains.clear();
                vals.clear();
                int idx = 0;
                for (int v = 0; v < n; v++) {
                        if(par[v] < 0 or heavy[par[v]] != v) {
                                chains.push_back(vector<int>());
                                vals.push_back(vector<int>());
                                for (int w = v; w != -1; w = heavy[w]) {
                                        chain[w] = idx;
                                        head[w] = v;
                                        id[w] = chains.back().size();
                                        chains.back().push_back(w);
                                        vals.back().push_back(val[w]);
                                }
                                idx++;
                        }
                }
        }
        HL_Decomposition(){}
        HL_Decomposition(int n) : n(n){}
 
        // do exec after use
        void new_val(int i, int v) { val[i] = v;}
        void add_edge(int u, int v) {
                G[u].push_back(v);
                G[v].push_back(u);
        }
        void exec() { hl_bfs();}
 
        // can not use before exec
        int lca(int u, int v)
        {
                while (chain[u] != chain[v]) {
                        if (dep[head[u]] > dep[head[v]]) swap(u,v);
                        v = par[head[v]];
                }
                return dep[u] < dep[v]? u: v;
        }
};
 
struct segtree
{
        int N;
        vector<int> left, right, sum, ans, delay, wait;
        segtree(vector<int> &ch) : wait(0){
                N = 1;
                while(N < (int)ch.size()) N *= 2;
                left.assign(2*N-1, -inf);
                right.assign(2*N-1, -inf);
                sum.assign(2*N-1, 0);
                ans.assign(2*N-1, -inf);
                delay.assign(2*N-1, 0);
                wait.assign(2*N-1, 0);
                for (int i = 0; i < (int)ch.size(); i++)
                        sum[i+N-1] = left[i+N-1] = right[i+N-1] = ans[i+N-1] = ch[i];
 
                for (int i = N-2; i >= 0; i--) {
                        sum[i]   = sum[2*i+1]+sum[2*i+2];
                        left[i]  = max(left[2*i+1],  sum[2*i+1]+left[2*i+2]);
                        right[i] = max(right[2*i+2], sum[2*i+2]+right[2*i+1]);
                        ans[i]   = max({ans[2*i+1], ans[2*i+2], right[2*i+1]+left[2*i+2]});
                }
        }
        void update(int l, int r, int v) { update(l,r,0,N,0,v);}
        void update(int a, int b, int l, int r, int k, int v) {
                if(b <= l or r <= a) return;
                if(a <= l and r <= b) {
                        if(r-l > 1) {
                                delay[k] = v;
                                wait[k] = 1;
                        }
                        if(v < 0) left[k] = right[k] = ans[k] = v;
                        else left[k] = right[k] = ans[k] = v*(r-l);
                        sum[k] = v*(r-l);
                        return;
                }
                const int m = (l+r)/2;
                if(wait[k]) {
                        update(l,m,l,m,2*k+1,delay[k]);
                        update(m,r,m,r,2*k+2,delay[k]);
                        wait[k] = 0;
                }
                update(a,b,l,m,2*k+1,v); update(a,b,m,r,2*k+2,v);
                sum[k]   = sum[2*k+1] + sum[2*k+2];
                left[k]  = max(left[2*k+1], sum[2*k+1]+left[2*k+2]);
                right[k] = max(right[2*k+2], sum[2*k+2]+right[2*k+1]);
                ans[k]   = max({ans[2*k+1], ans[2*k+2], right[2*k+1]+left[2*k+2]});
        }
 
        int summation(int l, int r) { return r<=l? 0: summation(l,r,0,N,0);}
        int summation(int a, int b, int l, int r, int k) {
                if(b <= l or r <= a) return 0;
                if(a <= l and r <= b) return sum[k];
                const int m = (l+r)/2;
                if(wait[k]) {
                        update(l,m,l,m,2*k+1,delay[k]);
                        update(m,r,m,r,2*k+2,delay[k]);
                        delay[k] = wait[k] = 0;
                }
                return summation(a,b,l,m,2*k+1)+summation(a,b,m,r,2*k+2);
        }
 
        int maximum(int l, int r) { return r<=l? -inf: maximum(l,r,0,N,0);}
        int maximum(int a, int b, int l, int r, int k) {
                if(b <= l or r <= a) return -inf;
                if(a <= l and r <= b) return ans[k];
                const int m = (l+r)/2;
                if(wait[k]) {
                        update(l,m,l,m,2*k+1,delay[k]);
                        update(m,r,m,r,2*k+2,delay[k]);
                        delay[k] = wait[k] = 0;
                }
                return max({maximum(a,b,l,m,2*k+1),
                            maximum(a,b,m,r,2*k+2),
                            right_max(a,b,l,m,2*k+1)+left_max(a,b,m,r,2*k+2)});
        }
 
        int left_max(int l, int r) { return r<=l? -inf: left_max(l,r,0,N,0);}
        int left_max(int a, int b, int l, int r, int k) {
                if(b <= l or r <= a) return -inf;
                if(a <= l and r <= b) return left[k];
                const int m = (l+r)/2;
                if(wait[k]) {
                        update(l,m,l,m,2*k+1,delay[k]);
                        update(m,r,m,r,2*k+2,delay[k]);
                        delay[k] = wait[k] = 0;
                }
 
                int ret = left_max(a,b,l,m,2*k+1);
                if(l < b and a < m) ret = max(ret, summation(a,b,l,m,2*k+1) + max(0LL,left_max(a,b,m,r,2*k+2)));
                else ret = left_max(a,b,m,r,2*k+2);
                return ret;
        }
 
        int right_max(int l, int r) { return r<=l? -inf: right_max(l,r,0,N,0);}
        int right_max(int a, int b, int l, int r, int k) {
                if(b <= l or r <= a) return -inf;
                if(a <= l and r <= b) return right[k];
                const int m = (l+r)/2;
                if(wait[k]) {
                        update(l,m,l,m,2*k+1,delay[k]);
                        update(m,r,m,r,2*k+2,delay[k]);
                        delay[k] = wait[k] = 0;
                }
 
                int ret = right_max(a,b,m,r,2*k+2);
                if(m < b and a < r) ret = max(ret, max(0LL, right_max(a,b,l,m,2*k+1)) + summation(a,b,m,r,2*k+2));
                else ret = right_max(a,b,l,m,2*k+1);
                return ret;
        }
};
 
int n, q;
HL_Decomposition hld;
vector<segtree> sts;
 
// u is ancestor of v
void update_sub(int u, int v, int c)
{
        while(chain[u] != chain[v]) {
                sts[chain[v]].update(0,id[v]+1,c);
                v = par[head[v]];
        }
        sts[chain[v]].update(id[u],id[v]+1,c);
}
 
void update(int u, int v, int c)
{
        int w = hld.lca(u,v);
        update_sub(w,u,c);
        update_sub(w,v,c);
}
 
void query_sub(int w, int &v, int &sq, int &mx)
{
        sq = mx = -inf;
        while(chain[v] != chain[w]) {
                mx = max({mx,
                          sts[chain[v]].maximum(0, id[v]+1),
                          sts[chain[v]].right_max(0, id[v]+1)+sq});
                sq = max(sts[chain[v]].summation(0, id[v]+1)+sq,
                         sts[chain[v]].left_max(0, id[v]+1));
                v = par[head[v]];
        }
}
 
int query(int u, int v)
{
        int w = hld.lca(u,v), usq, umx, vsq, vmx;
        query_sub(w,u,usq,umx);
        umx = max({umx,
                   sts[chain[u]].maximum(id[w], id[u]+1),
                   sts[chain[u]].right_max(id[w], id[u]+1)+usq});
        usq = max(sts[chain[u]].summation(id[w], id[u]+1)+usq,
                  sts[chain[u]].left_max(id[w], id[u]+1));
 
        query_sub(w,v,vsq,vmx);
        vmx = max({vmx,
                   sts[chain[v]].maximum(id[w]+1, id[v]+1),
                   sts[chain[v]].right_max(id[w]+1, id[v]+1)+vsq});
        vsq = max(sts[chain[v]].summation(id[w]+1, id[v]+1)+vsq,
                  sts[chain[v]].left_max(id[w]+1, id[v]+1));
 
        return max({umx, vmx, usq+vsq});
}
 
void solve()
{
        hld.exec();
        for(auto &vs: hld.vals) sts.push_back(segtree(vs));
        while(q--) {
                int t, u, v, c;
                scanf("%lld%lld%lld%lld", &t, &u, &v, &c);
                u--; v--;
                if(t == 1) update(u,v,c);
                else printf("%lld\n", query(u,v));
        }
}
 
void input()
{
        scanf("%lld%lld", &n, &q);
        hld = HL_Decomposition(n);
        for (int i = 0; i < n; i++) scanf("%lld", val+i);
        int a, b;
        for (int i = 0; i < n-1; i++) {
                scanf("%lld%lld", &a, &b);
                hld.add_edge(a-1,b-1);
        }
}
 
signed main()
{
        input();
        solve();
        return 0;
}