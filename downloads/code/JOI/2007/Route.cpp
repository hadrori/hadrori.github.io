#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0), eps = 1e-8;
const int inf = 1e9;
typedef complex<double> point;
typedef pair<int,int> pii;

struct node
{
        int u, v, c;
        bool operator<(const node &n) const { return c > n.c;}
};

int n, m, d[128][128];
vector<point> V;
vector<pii> G[128];

double arg(int u, int v, int w)
{
        point p = V[u], q = V[v], r = V[w];
        return arg(p-q)-arg(r-q);
}

bool can(double th)
{
        th = abs(th);
        if(th > pi) th -= 2*pi;
        return pi/2-eps < abs(th);
}

int solve()
{
        memset(d,-1,sizeof(d));
        priority_queue<node> q;
        for(auto &e: G[0]) q.push((node){0,e.first,e.second});

        int ans = inf;
        while(!q.empty()) {
                node a = q.top(); q.pop();
                if(d[a.v][a.u] >= 0) continue;
                d[a.v][a.u] = a.c;
                if(a.v == 1) ans = min(ans, a.c);
                for(auto &e: G[a.v])
                        if(can(arg(a.u,a.v,e.first)))
                                q.push((node){a.v, e.first, a.c+e.second});
        }
        
        return ans >= inf? -1: ans;
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
                int x, y;
                cin >> x >> y;
                V.push_back(point(x,y));
        }
        for (int i = 0; i < m; i++) {
                int x, y, c;
                cin >> x >> y >> c;
                x--; y--;
                G[x].push_back(pii(y,c));
                G[y].push_back(pii(x,c));
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
