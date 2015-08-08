#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

inline void chmin(int &x, int y) { x = ~x? min(x,y): y; }

struct node {
    int v, d;
    node(int v, int d):v(v),d(d){}
    bool operator<(const node &n)const{ return d > n.d;}
};

const int MAX = 1024;
struct edge{ int to, d; };
vector<edge> G[MAX];
int dist[MAX][MAX];

void dijkstra(int s) {
    memset(dist[s], -1, sizeof(dist[s]));
    priority_queue<node> q;
    q.push(node(s, 0));
    while(!q.empty()){
        int v = q.top().v, d = q.top().d;
        q.pop();
        if(~dist[s][v] and dist[s][v] <= d) continue;
        dist[s][v] = d;
        for(int i = 0; i < (int)G[v].size(); i++)
            q.push(node(G[v][i].to, d+G[v][i].d));
    }
}

int n, m, k, p, s[1024], t[1024], d[16][16], dp[1<<12][16];

void solve()
{
    dijkstra(p);
    rep(i,k) {
        dijkstra(s[i]);
        dijkstra(t[i]);
    }

    memset(d,-1,sizeof(d));
    memset(dp,-1,sizeof(dp));
    m = 2*k;
    rep(i,k) repi(j,i,k) {
        d[i][j] = d[j][i] = dist[s[i]][s[j]];
        d[i][j+k] = d[j+k][i] = dist[s[i]][t[j]];
        d[i+k][j] = d[j][i+k] = dist[t[i]][s[j]];
        d[i+k][j+k] = d[j+k][i+k] = dist[t[i]][t[j]];
    }
    rep(i,k) dp[1<<i][i] = dist[p][s[i]];

    rep(i,1<<m) rep(j,m) if(~dp[i][j])
        rep(l,m) if(~d[j][l] and (l < k or (i>>(l-k))&1))
            chmin(dp[1<<l|i][l], dp[i][j]+d[j][l]);
    int ans = -1;
    rep(i,m) chmin(ans, dp[(1<<m)-1][i]);

    if(~ans) printf("%d\n", ans);
    else puts("Cannot deliver");
}

void input()
{
    scanf("%d%d%d%d", &n, &m, &k, &p);
    p--;
    rep(i,m) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        G[a].push_back((edge){b,c});
        G[b].push_back((edge){a,c});
    }
    rep(i,k) {
        scanf("%d%d", s+i, t+i);
        s[i]--; t[i]--;
    }
}

int main()
{
    input();
    solve();
    return 0;
}
