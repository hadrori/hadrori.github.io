#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
struct edge{
    int to, d, c;
    bool operator<(const edge &e)const{
        if(d != e.d) return d > e.d;
        return c > e.c;
    }
};
int N, M;
vector<edge> G[10010];
int done[10010];

int solve(){
    memset(done, 0, sizeof(done));
    priority_queue<edge> que;
    int ans = 0;
    que.push((edge){0,0,0});
    while(!que.empty()){
        int v = que.top().to;
        int d = que.top().d, c = que.top().c;
        que.pop();
        if(done[v]) continue;
        done[v] = 1;
        ans += c;
        rep(i,G[v].size())
            que.push((edge){G[v][i].to, d+G[v][i].d, G[v][i].c});
    }
    return ans;
}

bool input(){
    cin >> N >> M;
    if(!N and !M) return 0;
    rep(i,N) G[i].clear();
    rep(i,M){
        int u, v, d, c;
        cin >> u >> v >> d >> c;
        u--; v--;
        G[u].pb((edge){v,d,c});
        G[v].pb((edge){u,d,c});
    }
    return 1;
}
signed main(){
    while(input()) cout << solve() << endl;
    return 0;
}

