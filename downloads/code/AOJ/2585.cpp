#include <bits/stdc++.h>
using namespace std;
 
struct edge
{
        int to, c, h, r;
};
 
struct node
{
        int v, c, h;
        bool operator<(const node &u) const {
                if(c != u.c) return c > u.c;
                return h > u.h;
        }
};
 
int n, m, h, k, s, t, p;
int pass[256], done[128][32], ps[256];
vector<edge> G[128];
 
int dijkstra(int f, int ub)
{
        priority_queue<node> q;
        q.push((node){s,pass[f],0});
        memset(done,0,sizeof(done));
        
        while(!q.empty()) {
                node u = q.top(); q.pop();
                if(u.v == t or u.c >= ub) return u.c;
                if(done[u.v][u.h]) continue;
                done[u.v][u.h] = 1;
                
                for(auto &e: G[u.v]) {
                        if(u.h+e.h > h) continue;
                        if(f&(1<<e.r)) q.push((node){e.to, u.c, u.h+e.h});
                        else q.push((node){e.to, u.c+e.c, u.h+e.h});
                }
        }
        return 1e9;
}
 
int solve()
{
        pass[0] = 0;
        int ans = 1e9;
        for (int i = 0; i < 1<<k; i++) {
                if(pass[i] >= ans) continue;
                ans = min(ans, dijkstra(i, ans));
                for (int j = 0; j < p; j++) {
                        pass[i|ps[j]] = min(pass[i|ps[j]], pass[i]+pass[ps[j]]);
                }
        }
 
        return ans < 1e9? ans: -1;
}
 
void init()
{
        for (int i = 0; i < 128; i++) G[i].clear();
        fill(pass,pass+256,1e9);
}
 
bool input()
{
        cin >> n >> m >> h >> k;
        if(!n) return 0;
        init();
        for (int i = 0; i < m; i++) {
                int a, b, c, h, r;
                cin >> a >> b >> c >> h >> r;
                --a; --b; --r;
                G[a].push_back((edge){b,c,h,r});
                G[b].push_back((edge){a,c,h,r});
        }
        cin >> s >> t >> p;
        --s; --t;
        for (int i = 0; i < p; i++) {
                int l, d, a, as = 0;
                cin >> l >> d;
                for (int j = 0; j < l; j++) {
                        cin >> a;
                        as |= 1<<(a-1);
                }
                ps[i] = as;
                pass[as] = d;
        }
        return 1;
}
 
int main()
{
        while(input()) cout << solve() << endl;
        return 0;
}
