#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> G[1<<15];
vector<int> vs;
int dep[1<<15], dp[1<<15], par[1<<15], dist[1<<15];

void dfs(int v, int u, int d)
{
        dep[v] = d;
        par[v] = u;
        for(auto &p: G[v]) {
                if(p.first == u) continue;
                dist[p.first] = p.second;
                dfs(p.first,v,d+1);
        }
}

bool cmp(const int &u, const int &v)
{
        return dep[u] > dep[v];
}

bool ok(int x)
{
        memset(dp,0,sizeof(dp));
        int cnt = 0;
        for(auto &v: vs) {
                int &u = par[v];
                
                if(dp[v]+dist[v] > x) cnt++;
                else if(dp[u] + dp[v] + dist[v] > x) {
                        cnt++;
                        dp[u] = min(dp[u], dp[v]+dist[v]);
                }
                else dp[u] = max(dp[u], dp[v]+dist[v]);
        }
        return cnt < m;
}

int solve()
{
        dfs(0,-1,0);
        for (int i = 1; i < n; i++) vs.push_back(i);
        sort(begin(vs),end(vs),cmp);
        
        int lb = -1, ub = n*100, mid;
        while(ub-lb>1) {
                mid = (lb+ub)>>1;
                if(ok(mid)) ub = mid;
                else lb = mid;
        }
        return ub;
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < n-1; i++) {
                int u, v, d;
                cin >> u >> v >> d;
                u--; v--;
                G[u].push_back(make_pair(v,d));
                G[v].push_back(make_pair(u,d));
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
