#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int inf = 1e9;

int n, m, k, chk[1024], done[1024], rev[1024], d[1024][1024], dp[1024][1024];
vector<pii> G[1024];
vector<int> vs, ps;

inline void chmin(int &a, int b){a=min(a,b);}

void topo_dfs(int v)
{
        if(done[v]) return;
        done[v] = 1;
        for(auto &e: G[v]) topo_dfs(e.first);
        vs.push_back(v);
}

void topological_sort()
{
        topo_dfs(0);
        reverse(begin(vs),end(vs));
}

void dijkstra(int s)
{
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push(pii(0,s));
        while(!q.empty()) {
                int v = q.top().second, c = q.top().first;
                q.pop();
                if(d[s][v] < inf) continue;
                d[s][v] = c;
                for(auto &e: G[v]) q.push(pii(c+e.second,e.first));
        }
}

int solve()
{
        topological_sort();
        for(auto &v: vs) {
                if(!chk[v]) continue;
                fill(d[v],d[v]+n,inf);
                fill(dp[v],dp[v]+n,inf);
                ps.push_back(v);
                dijkstra(v);
        }
        ps.push_back(n);

        dp[0][0] = 0;
        for (int i = 0; i < k; i++) {
                int &v = ps[i], &w = ps[i+1];
                d[v][v] = 0;
                for (int j = 0; j <= i; j++) {
                        int &u = ps[j];
                        chmin(dp[w][u], dp[v][u]+d[v][w]);
                        chmin(dp[w][v], dp[v][u]+d[u][w]);
                        chmin(dp[v][v], dp[v][u]+d[u][v]);
                }
        }
        return dp[n-1][n-1];
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
                cin >> chk[i];
                if(!i or i==n-1) chk[i] = 1;
                k += chk[i];
        }
        int a, b, c;
        for (int i = 0; i < m; i++) {
                cin >> a >> b >> c;
                G[a-1].push_back(pii(b-1,c));
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
