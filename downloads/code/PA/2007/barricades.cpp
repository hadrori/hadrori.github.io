#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;

inline void chmin(int &a, int b) { a = min(a,b);}

int n, m, sz[1<<12];
vector<int> g[1<<12], dp[1<<12];

int dfs(int v, int p)
{
        dp[v].assign(2,0);
        sz[v] = 1;
        for (int i = 0; i < (int)g[v].size(); i++) {
                if(g[v][i] == p) continue;
                sz[v] += dfs(g[v][i],v);
                dp[v].resize(sz[v]+1,inf);
                dp[n].assign(sz[v]+1,inf);
                for (int j = 1; j <= sz[v]; j++) {
                        chmin(dp[n][j],dp[v][j]+1);
                        for (int a = 1; a < j; a++)
                                if(sz[g[v][i]] >= j-a)
                                        chmin(dp[n][j], dp[v][a]+dp[g[v][i]][j-a]);
                }
                swap(dp[v],dp[n]);
        }
        return sz[v];
}

void solve()
{
        dfs(0,-1);
        int k;
        while(m--) {
                scanf("%d", &k);
                int ans = dp[0][k];
                for (int i = 1; i < n; i++)
                        if(sz[i] >= k) chmin(ans, dp[i][k]+1);
                printf("%d\n", ans);
        }
}

void input()
{
        scanf("%d", &n);
        int u, v;
        for (int i = 0; i < n-1; i++) {
                scanf("%d%d", &u, &v); u--; v--;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        scanf("%d", &m);
}

int main()
{
        input();
        solve();
        return 0;
}