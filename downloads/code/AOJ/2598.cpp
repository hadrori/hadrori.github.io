#include <bits/stdc++.h>
using namespace std;

inline void chmax(int &x, int y) { x = max(x, y); }

int n, m, t, p[128], q[128], r[128], sn;
vector<int> G[128], rG[128], vs, scc[128], to[128];
int self[128], done[128], belong[128], cnt[128];

void topo_dfs(int v)
{
        if(done[v]) return;
        done[v] = 1;
        for(auto &e: G[v]) topo_dfs(e);
        vs.push_back(v);
}

void scc_dfs(int v, int id)
{
        if(~belong[v]) return;
        belong[v] = id;
        scc[id].push_back(v);
        for(auto &e: rG[v]) scc_dfs(e, id);
}

void strongly_cc()
{
        for (int i = 0; i < n; i++) topo_dfs(i);
        reverse(begin(vs),end(vs));
        sn = 0;
        for (int i = 0; i < n; i++) if(!~belong[vs[i]]) scc_dfs(vs[i],sn++);
}

void scc_topo_dfs(int v)
{
        if(done[v]) return;
        done[v] = 1;
        for(auto &e: to[v]) scc_topo_dfs(e);
        vs.push_back(v);
}

int dp[128][10010];

int solve()
{
        strongly_cc();

        for (int i = 0; i < n; i++)
                for(auto &e: G[i])
                        if(belong[e] != belong[i])
                                to[belong[i]].push_back(belong[e]);
        for (int i = 0; i < sn; i++) {
                sort(begin(to[i]),end(to[i]));
                to[i].erase(unique(begin(to[i]),end(to[i])), end(to[i]));
        }

        vs.clear();
        memset(done,0,sizeof(done));
        for (int i = 0; i < sn; i++) scc_topo_dfs(i);
        reverse(begin(vs),end(vs));

        int ans = 0;
        for(auto &si: vs) {
                if((int)scc[si].size() == 1 and !self[scc[si][0]]) r[scc[si][0]] = 1;
                for(auto &i: scc[si]) {
                        int num = r[i];
                        for (int k = 1; num > 0; k <<= 1) {
                                int mul = min(k, num);
                                for (int j = t; j >= q[i]*mul; j--)
                                        chmax(dp[si][j], dp[si][j-q[i]*mul]+p[i]*mul);
                                num -= mul;
                        }
                }
                for(auto &e: to[si])
                        for (int j = 0; j <= t; j++)
                                chmax(dp[e][j], dp[si][j]);
                chmax(ans, dp[si][t]);
        }
        return ans;
}

void init()
{
        for (int i = 0; i < 128; i++) {
                G[i].clear();
                rG[i].clear();
                scc[i].clear();
                to[i].clear();
                self[i] = done[i] = cnt[i] = 0;
                belong[i] = -1;
        }
        memset(dp,0,sizeof(dp));
        vs.clear();
}

bool input()
{
        init();
        scanf("%d %d %d", &n, &m, &t);
        for (int i = 0; i < n; i++) scanf("%d %d %d", p+i, q+i, r+i);
        for (int i = 0; i < m; i++) {
                int a, b; scanf("%d %d", &a, &b); a--; b--;
                G[a].push_back(b);
                rG[b].push_back(a);
                if(a == b) self[a] = 1;
        }
        return n or m or t;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
