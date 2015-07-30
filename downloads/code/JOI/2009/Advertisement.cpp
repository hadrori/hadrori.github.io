#include <bits/stdc++.h>
using namespace std;

int n, m, f[100010], done[100010], id[100010];
vector<int> G[100010], rG[100010], vs;
vector<vector<int>> scc;

void dfs(int v) {
        if(done[v]) return;
        done[v] = 1;
        for(auto &u: G[v]) dfs(u);
        vs.push_back(v);
}

void rdfs(int v, int k) {
        if(done[v]) return;
        done[v] = 1;
        id[v] = k;
        scc.back().push_back(v);
        for(auto &u: rG[v]) rdfs(u,k);
}

int solve()
{
        for (int i = 0; i < n; i++) dfs(i);
        memset(done, 0, sizeof(done));
        reverse(begin(vs),end(vs));
        int k = 0;
        for(auto &v: vs)
                if(!done[v]) {
                        scc.push_back(vector<int>());
                        rdfs(v,k++);
                }
        for(auto &s: scc)
                for(auto &v: s){
                        if(f[id[v]]) break;
                        for(auto &u: rG[v])
                                if(id[u] != id[v]) f[id[v]] = 1;
                }

        int ans = 0;
        for (int i = 0; i < k; i++) ans += f[i]^1;
        return ans;
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                int a, b; cin >> a >> b;
                a--; b--;
                G[a].push_back(b);
                rG[b].push_back(a);
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
