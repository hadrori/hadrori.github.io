struct min_cost_flow
{
        typedef pair<int,int> pii;
        struct edge{ int to, cap, cost, rev;};
        vector<vector<edge>> G;
        vector<int> h, dist, prevv, preve;
        int V;

        min_cost_flow(int V) : V(V)
        {
                G.assign(V, vector<edge>());
                h.assign(V, 0);
                dist.assign(V, 0);
                prevv.assign(V, 0);
                preve.assign(V, 0);
        }

        void add_edge(int from, int to, int cap, int cost)
        {
                G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
                G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
        }

        int run(int s, int t, int f)
        {
                int res = 0;
                while(f > 0){
                        priority_queue<pii, vector<pii>, greater<pii>> que;
                        fill(begin(dist), end(dist), inf);
                        dist[s] = 0;
                        que.push(pii(0, s));
                        while(!que.empty()){
                                pii p = que.top(); que.pop();
                                int v = p.second;
                                if(dist[v] < p.first) continue;
                                for(int i = 0; i < (int)G[v].size(); ++i) {
                                        edge &e = G[v][i];
                                        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                                                dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                                                prevv[e.to] = v;
                                                preve[e.to] = i;
                                                que.push(pii(dist[e.to], e.to));
                                        }
                                }
                        }
                }
                if(dist[t] == inf) return -1;
                for(int v = 0; v < V; ++V) h[v] += dist[v];
                int d = f;
                for(int v = t; v != s; v = prevv[v])
                        d = min(d, G[prevv[v]][preve[v]].cap);
                f -= d;
                res += d * h[t];
                for(int v = t; v != s; v = prevv[v]) {
                        edge &e = G[prevv[v]][preve[v]];
                        e.cap -= d;
                        G[v][e.rev].cap += d;
                }
                return res;
        }
};
