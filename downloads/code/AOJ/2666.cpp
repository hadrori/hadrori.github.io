#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
 
int n, m, e, s, t, r;
int f[128][128], ev[128], dist[128][128][4];
 
int solve() {
    memset(dist,-1,sizeof(dist));
    queue<tuple<int,int,int,int>> q;
    q.push(make_tuple(s,0,0,0));
    int v, c, p, d;
    while(!q.empty()) {
        tie(v,c,p,d) = q.front(); q.pop();
        if(~dist[v][c][p]) continue;
        dist[v][c][p] = d;
        if(v == t) return d;
        if(~ev[v]) {
            p |= 1<<ev[v];
            q.push(make_tuple(s,0,p,d+1));
        }
        if(c == r) continue;
        rep(i,n) if(~f[v][i] and (f[v][i]|p) == (1<<e)-1) q.push(make_tuple(i,c+1,p,d+1));
    }
    return -1;
}
 
void input() {
    memset(ev,-1,sizeof(ev));
    memset(f,-1,sizeof(f));
    cin >> n >> m >> e >> s >> t >> r;
    int a, b, c;
    rep(i,m) {
        cin >> a >> b;
        f[a][b] = f[b][a] = (1<<e)-1;
    }
    rep(i,e) {
        cin >> a >> b >> c;
        ev[c] = i;
        f[a][b] = f[b][a] = ((1<<e)-1)-(1<<i);
    }
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}