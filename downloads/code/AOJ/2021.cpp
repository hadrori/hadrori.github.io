#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define INF 1e9

typedef pair<int,int> pii;
typedef pair<int,pii> P;

struct E{ int to, cost;};

int main(){
    int n, m, l, k, a, h;    
    while(cin >> n >> m >> l >> k >> a >> h, n||m||l||k||a||h){
        bool cooler[128] = {false};
        vector<vector<E> > G(n);
        rep(i,l){
            int t;
            cin >> t;
            cooler[t] = true;
        }
        rep(i,k){
            int s,t;
            E e;
            cin >> s >> t >> e.cost;
            e.to = t;
            G[s].pb(e);
            e.to = s;
            G[t].pb(e);
        }
        int d[128][128];
        priority_queue<P, vector<P>, greater<P> > que;
        rep(i,101) rep(j,101) d[i][j] = INF;
        d[a][m] = 0;
        que.push(mp(0,mp(a,m)));
        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second.first;
            int tm = p.second.second;
            if(d[v][tm] < p.first) continue;
            if(cooler[v]){
                rep(i,G[v].size()){
                    repi(j,tm,m+1){
                        E e = G[v][i];
                        if(j - e.cost >= 0 && d[e.to][j-e.cost] > d[v][tm] + e.cost + j - tm){
                            d[e.to][j-e.cost] = d[v][tm] + e.cost + j - tm;
                            que.push(P(d[e.to][j-e.cost], pii(e.to, j-e.cost)));
                        }
                    }
                }
            }else{
                rep(i,G[v].size()){
                    E e = G[v][i];
                    if(tm-e.cost >= 0 && d[e.to][tm-e.cost] > d[v][tm] + e.cost){
                        d[e.to][tm-e.cost] = d[v][tm] + e.cost;
                        que.push(P(d[e.to][tm-e.cost], pii(e.to, tm - e.cost)));
                    }
                }
            }
        }
        int ans = INF;
        rep(i,m+1) ans = min(ans, d[h][i]);
        if(ans!=INF)cout << ans << endl;
        else cout << "Help!\n";
    }
}
