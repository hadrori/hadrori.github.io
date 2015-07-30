#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back
#define INF 1e9

int dsp[] = {1,0,-1};

struct E{
    int to, d, c;
    E(int to, int d, int c):to(to),d(d),c(c){}
};

struct S{
    double time;
    int sp, city, prev;
    S(double time, int sp, int city, int prev):time(time),sp(sp),city(city),prev(prev){}
    bool operator > (const S &s) const{
        return time > s.time;
    }
};

int main(){
    int n, m;
    while(cin>>n>>m,n||m){
        int s, g;
        cin >> s >> g;
        s--; g--;
        vector<vector<E> > path(n);
        while(m--){
            int x, y, d, c;
            cin >> x >> y >> d >> c;
            x--; y--;
            path[x].pb(E(y,d,c));
            path[y].pb(E(x,d,c));
        }
        double dp[31][31][31];
        rep(i,31)rep(j,31)rep(k,31) dp[i][j][k] = INF;
        priority_queue<S, vector<S>, greater<S> > que;
        bool visited[31][31][31] = {false};
        dp[s][0][s] = 0;
        que.push(S(0,0,s,s));

        while(!que.empty()){
            S s = que.top(); que.pop();
            double time = s.time;
            int v = s.city, sp = s.sp, prev = s.prev;

            if(visited[v][sp][prev]) continue;
            visited[v][sp][prev] = true;

            rep(i,path[v].size()) if(path[v][i].to != prev){
                int nv = path[v][i].to;
                rep(j,3){
                    int nsp = sp + dsp[j];
                    if(nsp > 0 && nsp < 31 && nsp <= path[v][i].c && !visited[nv][nsp][v] && dp[nv][nsp][v] > time + (double) path[v][i].d / nsp){
                        dp[nv][nsp][v] = time + (double)path[v][i].d / nsp;
                        que.push(S(dp[nv][nsp][v], nsp, nv, v));
                    }
                }
            } 
        }
        double ans = INF;
        rep(i,n) ans = min(ans, dp[g][1][i]);
        if(ans == INF) cout << "unreachable\n";
        else printf("%.5f\n", ans);
    }
}
