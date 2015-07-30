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
