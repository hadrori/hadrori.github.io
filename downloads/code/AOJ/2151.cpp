#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back
#define INF 1e8
typedef vector<int> vi;

int n, m, l;

struct E{
    int to, dis, thief;
    E(int to, int dis, int thief):to(to),dis(dis),thief(thief){}
};

struct S{
    int attack, hotel, money;
    S(int attack, int hotel, int money):attack(attack),hotel(hotel),money(money){}
    bool operator > (const S &s) const{
        return attack > s.attack;
    }
};

int main(){
    while(cin >> n >> m >> l, n || m || l){
        vector<vector<E> > path(n);
        rep(i,m){
            int a, b, d, e;
            cin >> a >> b >> d >> e;
            a--; b--;
            path[a].pb(E(b,d,e));
            path[b].pb(E(a,d,e));
        }

        vector<vi> dp(n,vi(l+1,INF));
        dp[0][l] = 0;
        priority_queue<S, vector<S>, greater<S> > que;
        que.push(S(0,0,l));
        while(!que.empty()){
            S s = que.top(); que.pop();
            int d = s.attack, v = s.hotel, m = s.money;
            if(d > dp[v][m]) continue;
            rep(i,path[v].size()){
                int nv = path[v][i].to;
                int dis = path[v][i].dis;
                if(m - dis >= 0){
                    if(dp[nv][m-dis] > d){
                        dp[nv][m-dis] = d;
                        que.push(S(dp[nv][m-dis], nv, m-dis));
                    }
                }
                if(dp[nv][m] > d + path[v][i].thief){
                    dp[nv][m] = d + path[v][i].thief;
                    que.push(S(dp[nv][m], nv, m));
                }
            }
        }
        int ans = INF;
        rep(i,l+1) ans = min(ans, dp[n-1][i]);
        cout << ans << endl;   
    }
}
